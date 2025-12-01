#pragma once

#include "Shape.h"
#include <vector>

class Polygon : public Shape
{
public:

	// Constructor
	Polygon(std::string type, std::string name);

	// Destructor
	~Polygon();

	// Methods

	// Getters
	std::vector<Point> getPoints();

	// override functions if need (virtual + pure virtual)

protected:
	std::vector<Point> _points;
};