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
	double getPerimeter() const override;

	double* getLengths() const;

	void move(Point other) override;

	// Getters
	std::vector<Point> getPoints() const;

	// override functions if need (virtual + pure virtual)

protected:
	std::vector<Point> _points;
};