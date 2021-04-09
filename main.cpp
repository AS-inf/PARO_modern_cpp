#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

template<class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args)
{
    return shared_ptr<DerivedType>(new DerivedType(std::forward<Arguments>(args)...));
}

void printCollectionElements(const Collection& collection)
{
    for(const auto& it : collection)
        if(it)
            it->print();
}

void printAreas(const Collection& collection)
{
    for(const auto& it : collection)
        if(it)
            cout << it->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection, std::function<bool(shared_ptr<Shape>)> predicate, std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

constexpr int fibNth(int n, int a = 0, int b = 1)
{
    if(n>0)
    {
        int c=a;
        a=a+b;
        b=c;
        return fibNth(n-1, a, b);
    }
    return a;
}


int main()
{
    constexpr int fib = fibNth(45);
    cout<<fib<<endl;
    
    auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second) ->bool
    {
        if(first == nullptr || second == nullptr)
            return false;
        return (first->getArea() < second->getArea());
    };
    auto perimeterBiggerThan20 = [](shared_ptr<Shape> s) ->bool
    {
        if(s)
            return (s->getPerimeter() > 20);
        return false;
    };
    auto areaLessThanX = [x=10](shared_ptr<Shape> s) ->bool
    {
        if(s)
            return (s->getArea() < x);
        return false;
    };
    
    Collection moveShapes = {make_shared<Square>(4.5), make_shared<Rectangle>(Color::GREEN)};
    Collection shapes ={make_shape<Circle>(2.0),                // make_shared<Circle>(2.0),
                        make_shape<Circle>(3.0),                // make_shared<Circle>(3.0),
                        nullptr,
                        make_shared<Circle>(4.0),
                        make_shape<Rectangle>(10.0, 5.0),    //make_shared<Rectangle>(10.0, 5.0),
                        make_shared<Square>(3.0),
                        make_shared<Circle>(4.0),
                        make_shared<Circle>(Color::BLUE),
                        make_shared<Square>(Color::RED)
                        };
    {
        shared_ptr<Circle> moveRaw =make_shared<Circle>(3.5);
        shapes.push_back(std::move(moveRaw));
        move(moveShapes.begin(), moveShapes.end(), back_inserter(shapes));
    }   //destroy moveRaw
    
    
    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than X");

    return 0;
}

