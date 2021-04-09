#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r):Shape(Color::GREEN), r_(r)
{}

Circle::Circle(Color c): Shape(c)
{}

Circle::Circle(Color c, double r) : Circle(c)
{
    r_ = r;
}


double Circle::getArea() const noexcept
{
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const noexcept
{
    return 2 * M_PI * r_;
}

double Circle::getRadius() const
{
    return r_;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}

[[deprecated]]double Circle::getPi() const
{
    return M_PI;
}


