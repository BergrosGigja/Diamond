#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "log.h"

namespace Diamond
{
	Application::Application() 
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		DI_TRACE(e);

		while (true);
	}

}
