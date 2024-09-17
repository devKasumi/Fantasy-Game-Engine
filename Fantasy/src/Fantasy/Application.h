#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Fantasy {

	class FANTASY_API Application	// the declare spec se export or import dynamic dll
	{
	public:

		Application();

		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

