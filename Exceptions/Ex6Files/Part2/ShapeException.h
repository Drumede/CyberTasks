#pragma once
#include <exception>

class ShapeException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "This is a shape exception!";
    }
};
