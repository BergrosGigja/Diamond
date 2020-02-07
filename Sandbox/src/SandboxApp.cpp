#include <Diamond.h>

class Sandbox : public Diamond::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Diamond::Application* Diamond::CreateApplication()
{
	return new Sandbox();
}