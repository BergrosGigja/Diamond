#pragma once

#include "Core.h"

#include "Window.h"
#include "Diamond/Events/Event.h"
#include "Diamond/LayerStack.h"
#include "Diamond/Events/ApplicationEvent.h"

namespace Diamond 
{

	class DIAMOND_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in client
	Application* CreateApplication();
}

