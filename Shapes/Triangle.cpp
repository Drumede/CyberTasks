#include "Triangle.h"

// Constructor
Triangle::Triangle(Point a, Point b, Point c, std::string type, std::string name) : Polygon(type, name) {
	this->_points.push_back(a);
	this->_points.push_back(b);
	this->_points.push_back(c);

	if (this->getArea() <= 0) {
		std::cout << "Triangle cannot have an area of zero!" << std::endl;
		exit(1);
	}
}

// Destructor
Triangle::~Triangle() {

}

// Methods
double Triangle::getArea() const {
	double s = this->getPerimeter()/2;
	double* lengths = this->getLengths();
	double area = sqrt(s * (s - lengths[0]) * (s - lengths[1]) * (s - lengths[2]));
	delete[] lengths;
	return area;
}

void Triangle::draw(const Canvas& canvas)
{
	canvas.draw_triangle(_points[0], _points[1], _points[2]);
}

void Triangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_triangle(_points[0], _points[1], _points[2]);
}
