#pragma once
#include "Point.h"
#include "Canvas.h"
#include <string>
#include <iostream>

class Shape 
{
public:

	// Constructor
	Shape(std::string name, std::string type);

	// Destructor
	~Shape();

	// Getters
	std::string getType() const;
	std::string getName() const;

	// Methods
	virtual double getArea() const;
	virtual double getPerimeter() const;

	virtual void move(Point other); // add the Point to all the points of shape
	virtual void printDetails();

	virtual void draw(const Canvas& canvas) = 0;
	virtual void clearDraw(const Canvas& canvas) = 0;

private:
	std::string _name;
	std::string _type;
};