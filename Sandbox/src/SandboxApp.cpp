#include <Diamond.h>

class ExampleLayer : public Diamond::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//DI_INFO("ExampleLayer::Update");
		if (Diamond::Input::IsKeyPressed(DI_KEY_TAB))
			DI_TRACE("Tab pressed");
	}

	void OnEvent(Diamond::Event& event) override
	{
		//DI_TRACE("{0}", event);
	}
};

class Sandbox : public Diamond::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Diamond::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

Diamond::Application* Diamond::CreateApplication()
{
	return new Sandbox();
}