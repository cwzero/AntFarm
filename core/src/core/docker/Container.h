#pragma once

#include "core/Core.h"

#include <string>

namespace AntFarm
{
    class ANT_FARM_PUBLIC ContainerSpec
    {
    public:
        ContainerSpec(bool docker);
        ContainerSpec(bool docker, std::string image);
        ContainerSpec(bool docker, std::string prefix, std::string image, std::string tag);
        ~ContainerSpec();

        inline std::string GetImage() const { return _prefix + "/" + _image + ":" + _tag; };
        inline bool NeedsDocker() const { return _docker; };
    private:
        bool _docker = false;
        std::string _prefix = "liquidforte/ant_farm";
        std::string _image = "generation";
        std::string _tag = "latest";
    };

    class ANT_FARM_PUBLIC Container
    {
    public:
        Container(std::string id);
        ~Container();

        inline std::string GetId() const { return _id; };
    private:
        std::string _id;
    };
}