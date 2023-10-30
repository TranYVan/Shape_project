#include "Rectangle.h"

Rectangle::Rectangle() : IShape() {
    _fi = 1;
    _se = 1;
}

Rectangle::Rectangle(double first, double second) : IShape() {
    _fi = first;
    _se = second;
    if (_fi > _se) { std::swap(_fi, _se); }
}

double Rectangle::lengthFirstSide() {
    return _fi;
}

double Rectangle::lengthSecondSide() {
    return _se;
}

double Rectangle::perimeter() { return (_fi + _se) * 2; }

double Rectangle::area() { return _fi * _se * 1.0; }

string Rectangle::to_string() { return "Rectangle"; }

string Rectangle::ViName() { return "Hinh chu nhat"; }