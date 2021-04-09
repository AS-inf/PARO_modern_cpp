#pragma once

enum class Color : unsigned char
{
    BLUE,
    RED,
    GREEN
};


class Shape
{

public:
    Shape(Color c);
    Shape(const Shape& other)       = default;
    Shape(Shape&& other)noexcept    = default;
    
    virtual double getArea() const noexcept = 0;
    virtual double getPerimeter() const noexcept = 0;
    virtual void print() const;
    
    Shape& operator=(Shape&& other) noexcept =default;
    
    virtual ~Shape() {}

private:
    Shape() = delete;
    Color color{Color::RED};
};
