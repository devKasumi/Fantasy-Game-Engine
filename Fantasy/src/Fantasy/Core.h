#pragma once

#ifdef FT_PLATFORM_WINDOWS
	#ifdef FT_BUILD_DLL
		#define FANTASY_API __declspec(dllexport)	// define fantasy api -> dll export
	#else 
		#define FANTASY_API __declspec(dllimport)	
	#endif
#else 
#error Fantasy only support Windows !
#endif