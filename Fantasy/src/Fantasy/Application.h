#pragma once

#include "Core.h"

namespace Fantasy {

	class FANTASY_API Application	// the declare spec se export or import dynamic dll
	{
	public:

		Application();

		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

