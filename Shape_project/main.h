#pragma once

/*
include required library
*/

#include "Number.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <Windows.h>
#include <filesystem>

#include "IShape.h"
#include "IParser.h"
#include "RectangleShape.h"
#include "SquareShape.h"
#include "CircleShape.h"


using std::cout, std::cin, std::endl;
using std::string, std::to_string, std::wstring;
using std::vector;
using std::stringstream;
using std::fstream, std::ifstream, std::ofstream, std::ios;
using std::unordered_map;
using std::setw, std::left, std::right, std::setprecision, std::fixed;
using std::sort;
using std::set;
