#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "CircleShape.h"

Circle::Circle() {
	_r = 1;
}

Circle::Circle(double radius) {
	_r = radius;
}

double Circle::radiusLength() { return _r; }

double Circle::perimeter() { return _PI * 2 * _r; }

double Circle::area() { return _PI * _r * _r; }

string Circle::to_string() { return "Circle"; }

string Circle::ViName() { return "Hinh tron"; }

void Circle::printPerimeterArea(int no) {
	Double radius(this->radiusLength());
	string radius_str = radius.toString(2);

	Double perimeter(this->perimeter());
	string perimeter_str = perimeter.toString(1);

	Double area(this->area());
	string area_str = area.toString(2);
	cout << "| " << setw(3) << left << no
		<< "| " << setw(16) << left << ViName()
		<< "| " << setw(25) << left << "Ban kinh=" + radius_str
		<< "| " << setw(14) << left << "Chu vi=" + perimeter_str
		<< "| " << setw(14) << left << "Dien tich=" + area_str
		<< " |\n";
}

void Circle::printSize(int no)
{
	cout << no << ". " << "Hinh tron: Ban kinh=" << this->radiusLength() << endl;
}

///Parse data into Circle object
IShape* CircleParser::parse(stringstream data) {
	string buffer;
	getline(data, buffer, '=');
	double side = 0;
	getline(data, buffer);
	side = stod(buffer);
	return new Circle(side);
}

string CircleParser::to_string()
{
	return "Circle";
}

IParser* _cdecl createParser()
{
	return new CircleParser();
}