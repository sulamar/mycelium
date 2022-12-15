#include "Application.h"

int main(int argc, char* argv[])
{
	//Creating, initializing, and running application
	Application app;
	app.Init(1080, 720);
	app.Run();

	return 0;
}