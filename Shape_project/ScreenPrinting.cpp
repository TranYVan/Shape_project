#include "ScreenPrinting.h"

void ScreenPrinting::printPerimeterArea(IShape* shape, int no) {
	shape->printPerimeterArea(no);
}

void ScreenPrinting::printInfo(IShape* shape, int no)
{
	shape->printSize(no);
}

string ScreenPrinting::to_string()
{
	return "ScreenPrinting";
}
