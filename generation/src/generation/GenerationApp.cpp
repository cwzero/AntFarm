#include "generation/GenerationApp.h"
#include "core/EntryPoint.h"

#include <iostream>

namespace AntFarm
{
    Application *CreateApplication()
    {
        return new GenerationApp();
    }

    GenerationApp::GenerationApp()
    {

    }

    GenerationApp::~GenerationApp()
    {

    }

    bool GenerationApp::IsComplete()
    {
        return true;
    }

    void GenerationApp::Loop()
    {
        std::cout << "Generation App Running." << std::endl;
    }
}