#pragma once
#include <iostream>
#include <SDL.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include <Windows.h>
#include <fstream>
#include <thread>
#include "Line.h"
#include <string>
#include <sstream>

//Main application

//Things like SDL_Point have been commented out and replaced with Vector2 or Vector3
class Application
{
public:
	Application();
	~Application();

	//Initializes SDL_Window and SDL_Renderer
	void Init(unsigned int _width, unsigned int _height);

	//Runs main loop
	void Run();

private:
	SDL_Window* window;

	SDL_Renderer* renderer;

	//Window dimensions
	int width, height;

	//Boolion to see if app is running
	bool run;


	//Clear clears the screen, Render inserts the to be drawn objects on the renderer, Display draws the contents of the renderer on the window
	void Clear();
	void Render();
	void Display();

	//Buffer of lines to be drawn on screen
	std::vector<Line*> lineBuffer;

	//A starting point for all of the lines
	//SDL_Point start;

	Vector2<int> startPoint;

	//Can be used to leave lines in the background after they dissapear to create a certain kind of net of lines
	std::vector<Line*> net;

};