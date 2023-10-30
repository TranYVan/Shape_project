#pragma once
#include "main.h"

/// <summary>
/// Interface for print data to console
/// </summary>
class ScreenPrinting {
private:

public:
	/// <summary>
	/// Interface for printing the detail of perimeter and area of an shape's object
	/// </summary>
	/// <param name="shape"></param>
	/// <param name="no"></param>
	static void printPerimeterArea(IShape* shape, int no);
	
	/// <summary>
	/// Print size of each shape to screen.
	/// Ex: Radius of a circle, the side of a square
	/// </summary>
	/// <param name="shape"></param>
	/// <param name="no"></param>
	static void printInfo(IShape* shape, int no);
	string to_string();
};