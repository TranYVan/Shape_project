#include "IParserFactory.h"

/// <summary>
/// Find the coresponding IParser by input type
/// </summary>
/// <param name="type"> Type of shape </param>
/// <returns> Pointer of coresponding parser </returns>
IParser* IParserFactory::select(string type) {
	IParser* parser = nullptr;

	if (_prototypes.contains(type)) {
		parser = _prototypes[type];
	}
	return parser;
}

void IParserFactory::registerWith(string type, IParser* parser) {
	_prototypes.insert({ type, parser });
}

string IParserFactory::to_string() { return "IParser Factory"; }