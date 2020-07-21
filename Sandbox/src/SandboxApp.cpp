#include <Horus.h>


class Sandbox : public Horus::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Horus::Application* Horus::CreateApp()
{
	return new Sandbox();
}