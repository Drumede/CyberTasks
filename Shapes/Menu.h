#pragma once
#include "Shape.h"
#include "Canvas.h"
#include <vector>

enum MainSelect {
	NEW = 0,
	MODIFY,
	DELETEALL,
	EXIT
};

enum ShapeSelect {
	CIRC = 0,
	ARROW,
	TRI,
	RECT
};

class Menu
{
public:

	Menu();
	~Menu();

	// more functions..

private: 
	Canvas _canvas;
	std::vector<Shape> _shapes;
};

