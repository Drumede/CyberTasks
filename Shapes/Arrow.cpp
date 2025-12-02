#include "Arrow.h"

Arrow::Arrow(Point a, Point b, std::string type, std::string name) : Shape(name,type) {
	if (a == b) {
		std::cout << "The two points of an arrow cannot be the same!" << std::endl;
		exit(1);
	}
	this->_source = a;
	this->_destination = b;
}

// Destructor
Arrow::~Arrow() {
	this->_source.~Point();
	this->_destination.~Point();
}

// Getters
Point Arrow::getSource() const {
	return this->_source;
}
Point Arrow::getDestination() const {
	return this->_destination;
}

double Arrow::getArea() const {
	return 0;
}

double Arrow::getPerimeter() const {
	return this->_source.distance(this->_destination);
}

void Arrow::move(Point other) {
	this->_source += other;
	this->_destination += other;
}

void Arrow::printDetails() {
	return;
}

void Arrow::draw(const Canvas& canvas)
{
	canvas.draw_arrow(_source, _destination);
}
void Arrow::clearDraw(const Canvas& canvas)
{
	canvas.clear_arrow(_source, _destination);
}


