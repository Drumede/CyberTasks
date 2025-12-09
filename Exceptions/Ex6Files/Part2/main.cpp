#include "Circle.h"
#include "Quadrilateral.h"
#include "Rectangle.h"
#include "Parallelogram.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "ShapeException.h"
#include "InputException.h"

#include <string>
#include <iostream>
#include <limits>

// Helper: safely read a double or throw InputException
void readDoubleOrThrow(double& out)
{
    if (std::cin >> out)
        return;

    std::cin.clear();
    std::string discard;
    std::getline(std::cin, discard);
    throw InputException();
}

// Helper: safely read an int or throw InputException
void readIntOrThrow(int& out)
{
    if (std::cin >> out)
        return;

    std::cin.clear();
    std::string discard;
    std::getline(std::cin, discard);
    throw InputException();
}

int main()
{
    std::string nam, col;
    double rad = 0, ang = 0, ang2 = 180;
    int height = 0, width = 0;

    // Default objects (required for pointer usage in the original code)
    Circle circ("defaultCircle", "none", 1);
    Quadrilateral quad("defaultQuad", "none", 1, 1);
    rectangle rec("defaultRec", "none", 1, 1);
    Parallelogram para("defaultPara", "none", 1, 1, 0, 180);
    Pentagon pent("defaultPent", "none", 1);
    Hexagon hex("defaultHex", "none", 1);

    char exitKey = 'y';

    while (exitKey != 'x')
    {
        try {
            std::cout << "\nSelect shape:\n"
                << "c = circle\n"
                << "q = quadrilateral\n"
                << "r = rectangle\n"
                << "p = parallelogram\n"
                << "n = pentagon\n"
                << "h = hexagon\n";

            // Read a string to detect multi-character weird input
            std::string s;
            std::cin >> s;

            if (s.size() != 1) {
                std::cout << "Warning – Don’t try to build more than one shape at once\n";
                std::string extra;
                std::getline(std::cin, extra);
                continue;
            }

            char choice = s[0];

            switch (choice)
            {
            case 'c':
                std::cout << "Enter: color name radius\n";
                std::cin >> col >> nam;
                readDoubleOrThrow(rad);
                circ.setColor(col);
                circ.setName(nam);
                circ.setRad(rad);
                circ.draw();
                break;

            case 'q':
                std::cout << "Enter: name color height width\n";
                std::cin >> nam >> col;
                readIntOrThrow(height);
                readIntOrThrow(width);
                quad.setName(nam);
                quad.setColor(col);
                quad.setHeight(height);
                quad.setWidth(width);
                quad.draw();
                break;

            case 'r':
                std::cout << "Enter: name color height width\n";
                std::cin >> nam >> col;
                readIntOrThrow(height);
                readIntOrThrow(width);
                rec.setName(nam);
                rec.setColor(col);
                rec.setHeight(height);
                rec.setWidth(width);
                rec.draw();
                break;

            case 'p':
                std::cout << "Enter: name color height width angle1 angle2\n";
                std::cin >> nam >> col;
                readIntOrThrow(height);
                readIntOrThrow(width);
                readDoubleOrThrow(ang);
                readDoubleOrThrow(ang2);
                para.setName(nam);
                para.setColor(col);
                para.setHeight(height);
                para.setWidth(width);
                para.setAngle(ang, ang2);
                para.draw();
                break;

            case 'n':
                std::cout << "Enter: name color side\n";
                std::cin >> nam >> col;
                readDoubleOrThrow(rad);
                pent.setName(nam);
                pent.setColor(col);
                pent.setSide(rad);
                pent.draw();
                break;

            case 'h':
                std::cout << "Enter: name color side\n";
                std::cin >> nam >> col;
                readDoubleOrThrow(rad);
                hex.setName(nam);
                hex.setColor(col);
                hex.setSide(rad);
                hex.draw();
                break;

            default:
                std::cout << "Invalid selection.\n";
            }

            std::cout << "Press x to exit, any other key to continue: ";
            std::cin >> exitKey;
        }
        catch (const InputException& ie) {
            // Print message and recover input state
            std::cout << ie.what() << "\nPlease enter numeric values only.\n";
            continue;
        }
        catch (const ShapeException& se) {
            std::cout << se.what() << std::endl;
            continue;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
            continue;
        }
        catch (...) {
            std::cout << "Unknown exception caught.\n";
            continue;
        }
    }

    return 0;
}
