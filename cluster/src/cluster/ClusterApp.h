#pragma once

#include "core/Application.h"

namespace AntFarm
{
    class ClusterApp : public Application
    {
    public:
        ClusterApp();
        ~ClusterApp();

        virtual void Loop(int iter) override;
    };
}