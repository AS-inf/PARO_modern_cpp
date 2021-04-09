#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(Rectangle&& r) noexcept           = default;
    Rectangle(const Rectangle & other) noexcept = default;
    Rectangle(double x, double y);
    Rectangle(Color c);
    Rectangle(Color c, double x, double y);
    

    virtual double getArea() const noexcept(true) override;
    virtual double getPerimeter() const noexcept(true) override;
    virtual double getX() const final;
    virtual void print() const override;
    double getY() const;
    
    Rectangle& operator=(Rectangle&& other) noexcept = default;

private:
    Rectangle() = delete;

    double x_{0};
    double y_{0};
};
