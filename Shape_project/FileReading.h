#pragma once
#include "main.h"
#include <vector>
#include "IParserFactory.h"

using std::vector;

/// <summary>
/// Provide interfaces to users in order to read data of shapes from file to current program
/// </summary>
class FileReading {
private:
	/// <summary>
	/// Name of file that we need to read data
	/// </summary>
	string _path;
	/// <summary>
	/// Store the prototypes of all parsers.
	/// </summary>
	IParserFactory* _factory;

public:
	FileReading();
	FileReading(string path, IParserFactory* factory);
	/// <summary>
	/// Read data in file to a list of shapes
	/// </summary>
	/// <returns>Vector of shapes</returns>
	vector<IShape*> readFile();
	string to_string();
};