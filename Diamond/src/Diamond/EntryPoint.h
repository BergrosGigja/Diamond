#pragma once

#ifdef DI_PLATFORM_WINDOWS

extern Diamond::Application* Diamond::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Diamond::CreateApplication();
	app->Run();
	delete app;
}

#endif