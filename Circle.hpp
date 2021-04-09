#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
public:
    
    Circle(const Circle & other) noexcept      = default;
    Circle(Circle&& other) noexcept            = default;
    Circle(Color c, double r);
    Circle(double r);
    Circle(Color c);
    
    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getRadius() const;
    [[deprecated]]double getPi()const;
    void print() const override;
    
    Circle& operator=(Circle&& other) noexcept =default;

private:
    Circle() = delete;
    double r_{0};
};
