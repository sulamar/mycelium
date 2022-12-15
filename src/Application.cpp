#include "Application.h"


Application::Application()
	: window(nullptr), renderer(nullptr)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL2 init failed: error: " << SDL_GetError() << std::endl;
	}

	srand(time(NULL));
}

Application::~Application()
{
	SDL_Quit();
}

void Application::Init(unsigned int _width, unsigned int _height)
{
	width = _width;
	height = _height;

	window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_SHOWN);
	if (window == nullptr)
		std::cout << "Window creation failed: error: " << SDL_GetError() << std::endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
		std::cout << "Renderer creation failed: error: " << SDL_GetError() << std::endl;

	else
	{
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		run = true;
	}

}

void Application::Run()
{
	//Defining startPoint in the middle of the window
	startPoint = { width / 2, height / 2 };


	//Running opencv at the same time as mainloop
	//std::thread t([this] { this->opencv.Run(); });


	SDL_Event e;

	//Mainloop
	while (run)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
				run = false;
				break;
			case SDL_KEYDOWN:
				//Reset lines on the screen with r key
				if (e.key.keysym.sym == SDLK_r)
				{
					lineBuffer.clear();
					net.clear();
				}

			}
		}

		Clear();
		Render();
		Display();
	}
}


void Application::Clear()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Application::Render()
{
	//Getting data from a text file that arduino has outputted the serialdata into
	std::ifstream file("seriallog.log.txt");
	std::string line;
	
	if (file.is_open())
	{
		//Taking data from each line one by one
		std::getline(file, line);
			
		std::stringstream ss(line);
		int l = 0;
		
		//Placing the linedata into an int
		ss >> l;

		//int number contains data from file
		int number = l;
	

		/*SDL_Point point1 = {rand() % width, rand() % height};
		SDL_Point point2 = { rand() % width, rand() % height };

		//Setting random color for the line
		SDL_Color color;
		color.r = rand() % 256;
		color.g = rand() % 256;
		color.b = rand() % 256;*/


		//Generating points at random poisitions
		Vector2<int> point1 = { rand() % width, rand() % height };
		Vector2<int> point2 = { rand() % width, rand() % height };

		//Generating a random color (RGB)
		Vector3<char> color = { rand() % 255, rand() % 255, rand() % 255 };


		//Small delay to slow things down a little
		SDL_Delay(100);


		//Making the line and pushing it into the buffer of lines
		Line* li;

		li = new Line(startPoint, point2, 1, color, 17);

		lineBuffer.push_back(li);


		//Making sure the net of lines doesnt go to infinity
		if (net.size() > 200)
			net.erase(net.begin());

		net.push_back(li);

		//Rendering the lines in the net
		for (Line* line : net)
		{
			//line->color.x = red, line->color.y = green, line->color.z = blue
			SDL_SetRenderDrawColor(renderer, line->color.x, line->color.y, line->color.z, 50 );
			SDL_RenderDrawLine(renderer, line->point1.x, line->point1.y, line->point2.x, line->point2.y);
		}

		//Looping through each line and doing fading and rendering
		for (Line* line : lineBuffer)
		{
			if (line->opacity >= 255 && line->fadedin == false)
			{
				line->fadedin = true;
			}

			else if (line->fadedin == false)
			{
				line->opacity += line->fadeSpeed;
			}

			if (line->fadedin == true)
			{
				line->opacity -= line->fadeSpeed;;

			}

			//When line has faded out it gets erased
			if (line->opacity <= 0)
			{
				//Erases front object in the lineBuffer vector
				lineBuffer.erase(lineBuffer.begin());
			}
	
			//Making sure opacity doesn't go above 255
			if (line->opacity >= 255)
				line->opacity = 255;

			//Setting color and opacity for lines
			if(line->opacity > 0)
				SDL_SetRenderDrawColor(renderer, line->color.x, line->color.y, line->color.z, line->opacity);

			//Rendering the line
			SDL_RenderDrawLine(renderer, line->point1.x, line->point1.y, line->point2.x, line->point2.y);

		}

	}

	file.close();

}

void Application::Display()
{
	SDL_RenderPresent(renderer);
}

