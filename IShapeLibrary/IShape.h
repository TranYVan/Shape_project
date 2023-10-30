#ifndef _ISHAPE_H_
#define _ISHAPE_H_

#ifdef ISHAPELIBRARY_EXPORTS
#define ISHAPELIBRARY_API __declspec(dllexport)
#else
#define ISHAPELIBRARY_API __declspec(dllimport)
#endif

#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;


/// <summary>
/// Abstract class IShape: All specific shape's classes inheritance from this class.
/// </summary>
extern "C" ISHAPELIBRARY_API class IShape {
public:
	// Return name of shape
	virtual string to_string() = 0;
	// Return the perimeter of each shape object.
	virtual double perimeter() = 0;
	// Return the area of each shape object.
	virtual double area() = 0;
	// Return Vietnamese name of shape object
	virtual string ViName() = 0;

	virtual void printPerimeterArea(int no) = 0;

	virtual void printSize(int no) = 0;
};
	
#endif