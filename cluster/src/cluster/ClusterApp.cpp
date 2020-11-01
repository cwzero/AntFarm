#include "cluster/ClusterApp.h"
#include "core/EntryPoint.h"
#include "core/docker/Docker.h"

#include <iostream>

namespace AntFarm
{
    Application *CreateApplication(int argc, char **argv)
    {
        return new ClusterApp();
    }

    ClusterApp::ClusterApp() : Application()
    {

    }

    ClusterApp::~ClusterApp()
    {

    }

    void ClusterApp::Loop(int iter)
    {
        ContainerSpec *spec = new ContainerSpec(true);
        GetDocker()->RunContainer(spec);
    }
}