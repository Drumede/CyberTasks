#pragma once
#include "Polygon.h"


namespace myShapes
{
	// Calling it MyRectangle becuase Rectangle is taken by global namespace.
	class Rectangle : public Polygon
	{
	public:

		// Constructor
		// There's a need only for the top left corner 
		Rectangle(Point a, double length, double width, std::string type, std::string name);

		// Destructor
		~Rectangle();

		// Methods
		void draw(const Canvas& canvas) override;
		void clearDraw(const Canvas& canvas) override;

		// override functions if need (virtual + pure virtual)

		// Add Fields if necessary
	};
}