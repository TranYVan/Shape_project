#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include<Windows.h>
#include "RectangleShape.h"

Rectanglee::Rectanglee() {
	_fi = 1;
	_se = 1;

}

Rectanglee::Rectanglee(double first, double second) {
	_fi = first;
	_se = second;
	if (_fi > _se) { std::swap(_fi, _se); }
}

double Rectanglee::lengthFirstSide() { return _fi; }

double Rectanglee::lengthSecondSide() { return _se; }

double Rectanglee::perimeter() { return (_fi + _se) * 2; }

double Rectanglee::area() { return _fi * _se * 1.0; }

string Rectanglee::to_string() { return "Rectangle"; }

string Rectanglee::ViName() { return "Hinh chu nhat"; }

void Rectanglee::printPerimeterArea(int no) {
	Double firstSide(this->lengthFirstSide());
	string first_str = firstSide.toString(2);

	Double secondSide(this->lengthSecondSide());
	string second_str = firstSide.toString(2);

	Double perimeter(this->perimeter());
	string perimeter_str = perimeter.toString(1);

	Double area(this->area());
	string area_str = area.toString(2);

	cout << "| " << setw(3) << left << no
		<< "| " << setw(16) << left << this->ViName()
		<< "| " << setw(25) << left << "Rong=" + first_str + ", Cao=" + second_str
		<< "| " << setw(14) << left << "Chu vi=" + perimeter_str
		<< "| " << setw(14) << left << "Dien tich=" + area_str
		<< " |\n";
}

void Rectanglee::printSize(int no)
{
	cout << no << ". " << "Hinh chu nhat: Rong=" << this->lengthFirstSide()
		<< ", Cao=" << this->lengthSecondSide() << endl;
}

IShape* RectangleParser::parse(stringstream data)
{
	string buffer;
	getline(data, buffer, '=');
	double fi = 0;
	getline(data, buffer, ',');
	fi = stod(buffer);
	getline(data, buffer, '=');
	getline(data, buffer);
	double se = stod(buffer);
	return new Rectanglee(fi, se);
}

string RectangleParser::to_string()
{
	return "Rectangle";
}

SYS_TIME_FUNCS_DLL_API IParser* _cdecl createParser()
{
	return new RectangleParser();
}
