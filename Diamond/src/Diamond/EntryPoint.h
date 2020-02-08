#pragma once

#ifdef DI_PLATFORM_WINDOWS

extern Diamond::Application* Diamond::CreateApplication();

int main(int argc, char** argv)
{
	Diamond::Log::Init();
	DI_INFO("Welcome");

	auto app = Diamond::CreateApplication();
	app->Run();
	delete app;
}

#endif