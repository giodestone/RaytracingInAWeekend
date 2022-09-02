#include "Scene.h" // Contains App.h. Declared like this so App.h can be a reference (App&) in Scene.h

int main(int argc, char* args[])
{	
	App app;
	
	return app.OnExecute();
}