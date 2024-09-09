#pragma once

#ifdef FT_PLATFORM_WINDOWS

extern Fantasy::Application* Fantasy::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Fantasy::CreateApplication();
	app->Run();
	delete app;
}

#endif
