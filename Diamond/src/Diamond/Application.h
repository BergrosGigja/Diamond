#pragma once

#include "Core.h"

namespace Diamond 
{

	class DIAMOND_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}

