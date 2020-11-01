#pragma once

#include "Core.h"

namespace AntFarm
{
    class Docker;

    class ANT_FARM_PUBLIC Application
    {
    public:
        Application();
        Application(int max);
        virtual ~Application();

        virtual void Run();
        virtual bool IsComplete() { return _iter >= _max; }
        virtual void Loop(int iter) {};
    protected:
        virtual inline Docker *GetDocker() const { return _docker; };
    private:
        Docker *_docker;
        int _iter;
        int _max;
    };

    Application *CreateApplication(int argc, char **argv);
}