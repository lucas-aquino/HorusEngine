#pragma once


#ifdef HOR_PLATFORM_WINDOWS

extern Horus::Application* Horus::CreateApp();

int main(int argc, char** argv)
{

	Horus::Log::Init();

	HOR_CORE_WARN("Horus Start");
	HOR_INFO("Hola Var={0}", 5);

	auto app = Horus::CreateApp();
	app->Run();
	delete app;
}

#endif // HOR_PLATFORM_WINDOWS

