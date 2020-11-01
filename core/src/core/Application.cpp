#include "Application.h"
#include "core/docker/Docker.h"

namespace AntFarm
{
    Application::Application() : Application(1)
    {
        
    }

    Application::Application(int max) : 
        _max(max),
        _iter(0)
    {
        _docker = new Docker();
    }

    Application::~Application()
    {
        delete _docker;
    }

    void Application::Run()
    {
        do
        {
            Loop(_iter);
            _iter++;
        } while (!IsComplete());
    }
}