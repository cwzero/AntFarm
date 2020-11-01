#include "core/docker/Docker.h"

#include <curl/curl.h>
#include <iostream>

std::string jsonToString(rapidjson::Value& doc){
    rapidjson::StringBuffer buffer;
    buffer.Clear();
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    doc.Accept(writer);
    return std::string(buffer.GetString());
}

namespace AntFarm
{
    struct MemoryStruct {
        char *memory;
        size_t size;
    };
 
    static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
    {
        size_t realsize = size * nmemb;
        struct MemoryStruct *mem = (struct MemoryStruct *)userp;
 
        char *ptr = (char*)realloc(mem->memory, mem->size + realsize + 1);
        if(!ptr) {
            /* out of memory! */ 
            printf("not enough memory (realloc returned NULL)\n");
            return 0;
        }

        mem->memory = ptr;
        memcpy(&(mem->memory[mem->size]), contents, realsize);
        mem->size += realsize;
        mem->memory[mem->size] = 0;

        return realsize;
    }

    Docker::Docker()
    {
        curl_global_init(CURL_GLOBAL_ALL);
    }

    Docker::~Docker()
    {
        curl_global_cleanup();
    }

    Container *Docker::CreateContainer(ContainerSpec *spec)
    {
        rapidjson::Document request(rapidjson::kObjectType);
        request.AddMember("Image", spec->GetImage(), request.GetAllocator());

        if (spec->NeedsDocker()) {
            rapidjson::Value binds(rapidjson::kArrayType);
            binds.PushBack("/var/run/docker.sock:/var/run/docker.sock", request.GetAllocator());
            request.AddMember("Binds", binds, request.GetAllocator());
        }
         
        rapidjson::Document response = Request(POST, "containers/create", request);
        std::string id = response["Id"].GetString();
        return new Container(id);
    }

    void Docker::DeleteContainer(Container *container) {
        Request(DELETE, "containers/" + container->GetId(), NULL);        
    }
       
    void Docker::StartContainer(Container *container)
    {
        Request(POST, "containers/" + container->GetId() + "/start", NULL);
    }

    void Docker::WaitContainer(Container *container)
    {
        Request(POST, "containers/" + container->GetId() + "/wait", NULL);
    }

    void Docker::RunContainer(ContainerSpec *spec)
    {
        Container *container = CreateContainer(spec);
        StartContainer(container);
        WaitContainer(container);
        DeleteContainer(container);
    }

    rapidjson::Document Docker::Request(Method method, const std::string& path, const rapidjson::Document& param = NULL)
    {
        CURL *curl;
        CURLcode res;

        std::string method_str;
        std::string param_str;
        rapidjson::StringBuffer buffer;
        
        switch(method){
        case GET:
            method_str = "GET";
            break;
        case POST:
            method_str = "POST";
            break;
        case DELETE:
            method_str = "DELETE";
            break;
        case PUT:
            method_str = "PUT";
            break;
        default:
            method_str = "GET";
        }

        struct curl_slist *list = NULL;
        struct MemoryStruct chunk;
        chunk.memory = (char*)malloc(1);  /* will be grown as needed by realloc above */
        chunk.size = 0;    /* no data at this point */ 

        curl = curl_easy_init();
        if(!curl){
            std::cout << "error while initiating curl" << std::endl;
            curl_global_cleanup();
            exit(1);
        }

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1);
        curl_easy_setopt(curl, CURLOPT_UNIX_SOCKET_PATH, "/var/run/docker.sock");
        curl_easy_setopt(curl, CURLOPT_URL, ("http://localhost/v1.40/" + path).c_str());
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method_str.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        list = curl_slist_append(list, "Content-Type: application/json");
        list = curl_slist_append(list, "Accept: application/json");

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);

        if (method == POST && NULL != param)
        {
            buffer.Clear();
            rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
            param.Accept(writer);
            param_str = std::string(buffer.GetString());

            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, param_str.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, param_str.length());
        }
        
        res = curl_easy_perform(curl);
        
        unsigned status = 0;
        curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &status);

        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

            rapidjson::Document doc(rapidjson::kObjectType);
            doc.Parse(chunk.memory);
            
            std::cout << jsonToString(doc) << std::endl;
        }
        
        curl_slist_free_all(list);
        curl_easy_cleanup(curl);

        rapidjson::Document doc(rapidjson::kObjectType);
        doc.Parse(chunk.memory);
        free(chunk.memory);
        return doc;
    }
}