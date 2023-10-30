#ifndef _IPARSER_H_
#define _IPARSER_H_

#include "IShape.h"
#include <unordered_map>
using std::unordered_map;


/// <summary>
/// Abstract class: Manage each shape objects's parsing
/// </summary>
ISHAPELIBRARY_API class IParser {
public:
	virtual IShape* parse(stringstream data) = 0;
	virtual string to_string() = 0;
};

#endif
