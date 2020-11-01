#include "core/docker/Container.h"

namespace AntFarm
{
    ContainerSpec::ContainerSpec(bool docker) :
        _docker(docker)
    {

    }

    ContainerSpec::ContainerSpec(bool docker, std::string image) : 
        _docker(docker),
        _image(image)
    {

    }

    ContainerSpec::ContainerSpec(bool docker, std::string prefix, std::string image, std::string tag) : 
        _docker(docker),
        _prefix(prefix),
        _image(image),
        _tag(tag)
    {

    }

    Container::Container(std::string id) :
        _id(id)
    {

    }

    Container::~Container()
    {

    }
}