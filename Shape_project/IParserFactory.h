#pragma once
#include "main.h"

class IParserFactory {
private:
	unordered_map <string, IParser*> _prototypes;

public:
	/// <summary>
	/// Choose the parser corresponding to its shape
	/// </summary>
	/// <param name="type"> name of shape: Square, Rectangle...</param>
	/// <returns> A Parser pointer </returns>
	IParser* select(string type);

	/// <summary>
	/// Inject new shape to current program
	/// </summary>
	/// <param name="type"> Name of shape </param>
	/// <param name="parser"> Shape's parser </param>
	void registerWith(string type, IParser* parser);
	string to_string();
};