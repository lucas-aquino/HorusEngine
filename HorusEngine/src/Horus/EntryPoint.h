#pragma once


#ifdef HOR_PLATFORM_WINDOWS

extern Horus::Application* Horus::CreateApp();

int main(int argc, char** argv)
{
	auto app = Horus::CreateApp();
	app->Run();
	delete app;
}

#endif // HOR_PLATFORM_WINDOWS

