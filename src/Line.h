#pragma once
#include "math/Math.h"
#include <SDL.h>

struct Line
{
	Line(Vector2<int> p1, Vector2<int> p2, int op, Vector3<char> col, int _fadeSpeed);

	int opacity;

	Vector2<int> point1, point2;

	Vector3<char> color;

	int fadeSpeed;

	//Check if line has fadedin
	bool fadedin;
};

