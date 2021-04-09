#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(Square&& s) noexcept             = default;
    Square(const Square & other) noexcept   = default;
    Square(double x);
    Square(Color c);
    Square(Color c, double x);
    

    double getArea() const noexcept override ;
    double getPerimeter() const noexcept override;
    void print() const override;
    
    Square& operator=(Square&& other) noexcept = default;

private:
    double getY() = delete;
    Square() = delete;
};
