#include"FileReading.h"
#include "ScreenPrinting.h"
FileReading::FileReading() {
	_path = "";
}

FileReading::FileReading(string path, IParserFactory* factory) {
	_path = path;
	_factory = factory;
}

string FileReading::to_string() { return "File Reader"; }

vector<IShape*> FileReading::readFile() {

	vector<IShape*> shapeList;
	ifstream fin(_path, ios::in);

	if (fin.is_open()) {
		string line;
		stringstream buffer;
		
		int n;
		getline(fin, line);
		n = stoi(line);
		for (int i = 0; i < n; i++) {
			getline(fin, line);
			
			//Clear sstream and assign the ith line into it
			buffer.str("");
			buffer.clear();
			buffer.str(line);
			
			string type;
			getline(buffer, type, ':');
			string data;
			getline(buffer, data);

			IParser* parser = nullptr;
			parser = _factory->select(type);
			if (parser == nullptr) {
				continue;
			}
			IShape* shape = parser->parse(stringstream(data));
			shapeList.push_back(shape);
		}
		cout << "Dang doc tap tin " << _path << "..." << endl;
		cout << "Tim thay " << shapeList.size() << "/" << n << " hinh" << endl;
		for (int i = 0; i < shapeList.size(); i++) {
			ScreenPrinting::printInfo(shapeList[i], i+1);
		}
	}

	fin.close();

	return shapeList;
}

vector<IShape*> getShape() {

	vector<IShape*> shapeList;
	string str;
	getline(cin, str);
	int n = stoi(str);

	/*
	* Get each line from user and CREATE CORRESPOND SHAPE
	*/
	for (int i = 0; i < n; i++) {
		// Get type of shape: square, circle...
		string type;
		getline(cin, type);
		
		/* Get info of the shape
		* -> Length of side of square
		* -> length of radius of circle
		*/
		string data;
		getline(cin, data);

		// New shape's object
		IShape* newShape = nullptr;
		// Parser that we are going to choose.
		IParser* parser = nullptr;

		if (type == "Square") {
			parser = new SquareParser();
			newShape = parser->parse(data);
		}
		else if (type == "Circle") {
			parser = new CircleParser();
			newShape = parser->parse(data);
		}
		shapeList.push_back(newShape);
	}


	return shapeList;
}