#pragma once

#include "Core.h"

namespace Horus
{
	class HORUS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in the CLIENT
	Application* CreateApp();
}
