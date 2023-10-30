#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

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

class SYS_TIME_FUNCS_DLL_API Circle : public IShape {
private:
	inline static const double _PI = 3.14;
private:
	double _r;
public:
	// Constructor
	Circle();
	// Constructor with the argument is the length of radius of Circle object
	Circle(double radius);

public:
	// Return the length of radius of this Circle object.
	double radiusLength();
	// Return the perimeter of this Circle object.
	double perimeter();
	// Return the area of this Circle object.
	double area();

	string to_string();

	string ViName();

	void printPerimeterArea(int no);

	void printSize(int no);
};

/// <summary>
/// Manage square objects's parsing
/// </summary>
class SYS_TIME_FUNCS_DLL_API CircleParser : public IParser {
public:
	IShape* parse(stringstream data);
	string to_string();
};

extern "C" {
	SYS_TIME_FUNCS_DLL_API IParser* _cdecl createParser();
};


#endif