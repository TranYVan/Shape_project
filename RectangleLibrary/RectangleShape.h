#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

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

SYS_TIME_FUNCS_DLL_API class Rectanglee : public IShape {
private:
	// Two sides
	double _fi;
	double _se;

public:
	// Constructor
	Rectanglee();
	// Constructor with 2 arguments: Two sides of a rectangle object.
	Rectanglee(double first, double second);

public:
	// Length of the first side
	double lengthFirstSide();
	// Length of the second side;
	double lengthSecondSide();
	// Return the perimeter of the rectangle object.
	double perimeter();
	// Return the area of the rectangle object.
	double area();

	string to_string();

	string ViName();

	void printPerimeterArea(int no);

	void printSize(int no);
};

SYS_TIME_FUNCS_DLL_API class RectangleParser : public IParser {
public:
	IShape* parse(stringstream data);
	string to_string();
};

extern "C" {
	SYS_TIME_FUNCS_DLL_API IParser* _cdecl createParser();
};

#endif