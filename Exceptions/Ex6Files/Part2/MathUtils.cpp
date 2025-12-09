#include "MathUtils.h"

double MathUtils::CalPentagonArea(double a)
{
    return 0.25 * std::sqrt(5 * (5 + 2 * std::sqrt(5))) * a * a;
}

double MathUtils::CalHexagonArea(double a)
{
    return (3 * std::sqrt(3) / 2) * a * a;
}
