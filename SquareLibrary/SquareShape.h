#ifndef _SQUARE_H_
#define _SQUARE_H_
#include "IShape.h"
#include "IParser.h"
#include <Number.h>
#include <iomanip>
#include <iostream>

using std::cout, std::endl;
using std::setw, std::left, std::right, std::setprecision, std::fixed;

#ifdef SYS_TIME_DLL_EXPORTS
#define SYS_TIME_FUNCS_DLL_API  __declspec(dllexport)  
#else
#define SYS_TIME_FUNCS_DLL_API  __declspec(dllimport) 
#endif


class SYS_TIME_FUNCS_DLL_API Square : public IShape {
private:
	double _side;

public:
	// Constructor
	Square();
	// Constructor with argument is the length of side of this Square object.
	Square(double);

public:
	// Return the length of side of this square object.
	double sideLength();
	// Return the perimeter of this square object.
	double perimeter();
	// Return the area of this square object.
	double area();

	string to_string();

	string ViName();

	void printPerimeterArea(int no);

	void printSize(int no);
};

/// <summary>
/// Manage square objects's parsing
/// </summary>
class SYS_TIME_FUNCS_DLL_API SquareParser : public IParser {
public:
	IShape* parse(stringstream data);
	string to_string();
};

extern "C" {
	SYS_TIME_FUNCS_DLL_API IParser* _cdecl createParser();
};

#endif