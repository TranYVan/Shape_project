#pragma once

#include <iostream>
#include <iomanip>
#include <string>
using std::cout, std::cin, std::endl;
using std::fixed, std::setprecision;
using std::string;

// Double class to handle an double number
class Double {
private:
	double _val;
public:
	double value();
	Double();
	Double(double value);

	string toString(unsigned int precision);

public:
	void print(unsigned int setprecisor);
};

class Integer {
private:
	int _value;
public:
	int value();
	Integer(int value);

	string toString();
};
