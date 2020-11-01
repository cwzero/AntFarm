#include "organism/OrganismApp.h"
#include "core/EntryPoint.h"

namespace AntFarm
{
    Application *CreateApplication()
    {
        return new OrganismApp();
    }

    OrganismApp::OrganismApp()
    {

    }

    OrganismApp::~OrganismApp()
    {

    }

    bool OrganismApp::IsComplete()
    {
        return true;
    }

    void OrganismApp::Loop()
    {
        
    }
}