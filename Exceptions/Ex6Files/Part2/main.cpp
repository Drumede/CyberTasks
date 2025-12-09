#include "Circle.h"
#include "Quadrilateral.h"
#include "Rectangle.h"
#include "Parallelogram.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "ShapeException.h"

#include <iostream>
#include <string>
#include <limits>

bool readSafeDouble(double& out)
{
    if (std::cin >> out)
        return true;

    std::cout << "Invalid number. Try again.\n";
    std::cin.clear();
    std::string discard;
    std::getline(std::cin, discard);
    return false;
}

bool readSafeInt(int& out)
{
    if (std::cin >> out)
        return true;

    std::cout << "Invalid number. Try again.\n";
    std::cin.clear();
    std::string discard;
    std::getline(std::cin, discard);
    return false;
}

int main()
{
    std::string nam, col;
    double rad = 0, ang = 0, ang2 = 180;
    int height = 0, width = 0;

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
            std::cout << "\nShape menu:\n"
                << "c = circle\n"
                << "q = quadrilateral\n"
                << "r = rectangle\n"
                << "p = parallelogram\n"
                << "n = pentagon\n"
                << "h = hexagon\n";

            std::string s;
            std::cin >> s;

            if (s.size() != 1) {
                std::cout << "Warning – Don’t try to build more than one shape at once\n";
                std::string junk;
                std::getline(std::cin, junk);
                continue;
            }

            char choice = s[0];

            switch (choice)
            {
            case 'c':
                std::cout << "Enter color, name, radius:\n";
                std::cin >> col >> nam;
                if (!readSafeDouble(rad)) continue;
                circ.setColor(col);
                circ.setName(nam);
                circ.setRad(rad);
                circ.draw();
                break;

            case 'q':
                std::cout << "Enter name, color, height, width:\n";
                std::cin >> nam >> col;
                if (!readSafeInt(height)) continue;
                if (!readSafeInt(width)) continue;
                quad.setName(nam);
                quad.setColor(col);
                quad.setHeight(height);
                quad.setWidth(width);
                quad.draw();
                break;

            case 'r':
                std::cout << "Enter name, color, height, width:\n";
                std::cin >> nam >> col;
                if (!readSafeInt(height)) continue;
                if (!readSafeInt(width)) continue;
                rec.setName(nam);
                rec.setColor(col);
                rec.setHeight(height);
                rec.setWidth(width);
                rec.draw();
                break;

            case 'p':
                std::cout << "Enter name, color, height, width, angle1, angle2:\n";
                std::cin >> nam >> col;
                if (!readSafeInt(height)) continue;
                if (!readSafeInt(width)) continue;
                if (!readSafeDouble(ang)) continue;
                if (!readSafeDouble(ang2)) continue;
                para.setName(nam);
                para.setColor(col);
                para.setHeight(height);
                para.setWidth(width);
                para.setAngle(ang, ang2);
                para.draw();
                break;

            case 'n':
                std::cout << "Enter name, color, side:\n";
                std::cin >> nam >> col;
                if (!readSafeDouble(rad)) continue;
                pent.setName(nam);
                pent.setColor(col);
                pent.setSide(rad);
                pent.draw();
                break;

            case 'h':
                std::cout << "Enter name, color, side:\n";
                std::cin >> nam >> col;
                if (!readSafeDouble(rad)) continue;
                hex.setName(nam);
                hex.setColor(col);
                hex.setSide(rad);
                hex.draw();
                break;

            default:
                std::cout << "Invalid selection.\n";
                break;
            }

            std::cout << "Press x to exit, or any key to continue: ";
            std::cin >> exitKey;
        }
        catch (const ShapeException& e) {
            std::cout << e.what() << "\n";
            continue;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << "\n";
            continue;
        }
        catch (...) {
            std::cout << "Unknown error.\n";
            continue;
        }
    }

    return 0;
}
