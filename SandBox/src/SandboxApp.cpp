#include <Fantasy.h>

class Sandbox : public Fantasy::Application
{
public: 
	Sandbox() 
	{

	}

	~Sandbox()
	{

	}

};

Fantasy::Application* Fantasy::CreateApplication()
{
	return new Sandbox();
}