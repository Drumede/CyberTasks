#include "Rectangle.h"

myShapes::Rectangle::Rectangle(Point a, double length, double width, std::string type, std::string name) : Polygon(type, name) {
	if (length <= 0) {
		std::cout << "Rectangle cannot have a length/width of 0 or less!" << std::endl;
		exit(1);
	}
	this->_points.push_back(a);
	this->_points.push_back(a + Point(length, 0));
	this->_points.push_back(a + Point(length, width));
	this->_points.push_back(a + Point(0, width));
}

// Destructor
myShapes::Rectangle::~Rectangle() {

}

// Methods
double myShapes::Rectangle::getArea() const {
	double* lengths = this->getLengths();
	double area = lengths[0] * lengths[1];
	delete[] lengths;
	return area;
}

void myShapes::Rectangle::draw(const Canvas& canvas)
{
	canvas.draw_rectangle(_points[0], _points[1]);
}

void myShapes::Rectangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_rectangle(_points[0], _points[1]);
}


