#pragma once

#include "core/Application.h"

namespace AntFarm
{
    class GenerationApp : public Application
    {
    public:
        GenerationApp();
        ~GenerationApp();

        virtual bool IsComplete();
        virtual void Loop();
    };
}