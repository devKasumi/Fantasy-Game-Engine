#pragma once

#ifdef FT_PLATFORM_WINDOWS

extern Fantasy::Application* Fantasy::CreateApplication();

int main(int argc, char** argv)
{
	Fantasy::Log::Init();
	FT_CORE_WARN("Initialized Log!");
	int a = 5;
	FT_INFO("Hello World! Var={0}", a);

	auto app = Fantasy::CreateApplication();
	app->Run();
	delete app;
}

#endif
