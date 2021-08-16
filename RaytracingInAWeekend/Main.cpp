#include "App.h"

#include "SDL.h"
#undef main

int main()
{	
	App app;
	
	return app.OnExecute();
}