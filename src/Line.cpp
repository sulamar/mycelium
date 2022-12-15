#include "Line.h"

Line::Line(Vector2<int> p1, Vector2<int> p2, int op, Vector3<char> col, int _fadeSpeed)
{
	point1 = p1;
	point2 = p2;
	opacity = op;
	color = col;
	fadedin = false;
	fadeSpeed = _fadeSpeed;

}