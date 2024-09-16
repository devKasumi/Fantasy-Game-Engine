#include "ftpch.h"
#include "Application.h"

#include "Fantasy/Events/ApplicationEvent.h"
#include "Fantasy/Log.h"

namespace Fantasy {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);

		if (e.IsInCatergory(EventCategoryApplication))
		{
			FT_TRACE(e);
		}

		if (e.IsInCatergory(EventCategoryInput)) 
		{
			FT_TRACE(e);
		}
		

		while (true);
	}
}
