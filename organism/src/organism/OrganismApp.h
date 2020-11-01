#pragma once

#include "core/Application.h"

namespace AntFarm
{
    class OrganismApp : public Application
    {
    public:
        OrganismApp();
        ~OrganismApp();

        virtual bool IsComplete();
        virtual void Loop();
    };
}