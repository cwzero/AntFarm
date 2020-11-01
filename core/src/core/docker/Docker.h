#pragma once

#include "core/Core.h"
#include "core/docker/Container.h"

std::string jsonToString(rapidjson::Value& doc);

namespace AntFarm
{
    typedef enum {
        GET,
        POST,
        DELETE,
        PUT
    } Method;

    class ANT_FARM_PUBLIC Docker
    {
    public:
        Docker();
        ~Docker();

        Container *CreateContainer(ContainerSpec *spec);
        void DeleteContainer(Container *container);
        void StartContainer(Container *container);
        void WaitContainer(Container *container);
        void RunContainer(ContainerSpec *spec);

        rapidjson::Document Request(Method method, const std::string& path, const rapidjson::Document& param);
    };
}