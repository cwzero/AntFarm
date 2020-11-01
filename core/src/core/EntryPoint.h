#pragma once

namespace AntFarm
{
	extern Application* CreateApplication(int argc, char **argv);
}

int main(int argc, char** argv)
{
	auto app = AntFarm::CreateApplication(argc, argv);
	app->Run();
	delete app;
}