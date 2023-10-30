#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "SquareShape.h"

Square::Square() : IShape() {
	_side = 1;
}

Square::Square(double side) : IShape() {
	_side = side;
}

double Square::sideLength() { return _side; }

double Square::perimeter() {
	return _side * 4;
}

double Square::area() {
	return _side * _side;
}

string Square::to_string() { return "Square"; }

string Square::ViName() { return "Hinh vuong"; }

void Square::printPerimeterArea(int no)
{
	Double side(this->sideLength());
	string side_str = side.toString(2);

	Double perimeter(this->perimeter());
	string perimeter_str = perimeter.toString(1);

	Double area(this->area());
	string area_str = area.toString(2);



	cout << "| " << setw(3) << left << no
		<< "| " << setw(16) << left << this->ViName()
		<< "| " << setw(25) << left << "Canh=" + side_str
		<< "| " << setw(14) << left << "Chu vi=" + perimeter_str
		<< "| " << setw(14) << left << "Dien tich=" + area_str
		<< " |\n";
}

void Square::printSize(int no)
{
	cout << no << ". " << "Hinh vuong: Canh=" << this->sideLength() << endl;
}


/// Parse data into Square object
IShape* SquareParser::parse(stringstream data) {
	string buffer;
	getline(data, buffer, '=');
	double side = 0;
	getline(data, buffer);
	side = stod(buffer);
	return new Square(side);
}

string SquareParser::to_string() {
	return "Square";
}

SYS_TIME_FUNCS_DLL_API IParser* _cdecl createParser() {
	return new SquareParser();
}