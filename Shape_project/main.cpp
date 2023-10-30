/*
* SHAPE PROJECT
* Trần Ý Văn
* 21120360
* OOP Project
*/ 

#include "main.h"
#include "FileReading.h"
#include "ScreenPrinting.h"
#include "FileHandling.h"
#include <filesystem>

typedef IParser* (*CREATE_PARSER) ();

namespace fs = std::filesystem;

/// <summary>
/// Comparator for sorting the list of IShape base on their area.
/// </summary>
/// <param name="a">The previous IShape</param>
/// <param name="b">The second IShape</param>
/// <returns>True if a.area() < b.area() </returns>
bool compare(IShape* a, IShape* b) {
    if (a->area() < b->area()) return true;
    return false;
}

/// <summary>
/// After getting the position of a shape's DLL file, trying link explicitly it to this program.
/// If succeeded, inject that one to program.
/// </summary>
/// <param name="factory"> Interface for storing parsers.</param>
/// <param name="dir"> Path to the directory of DLL file.</param>
/// <param name="dllName"> Name of the DLL file.</param>
void getNextDll(IParserFactory*& factory, string& dir, string dllName);

int main() {
    IParserFactory* factory = new IParserFactory();

    // Store the name of all IShape's DLL that our project able to handle.
    set<string> setOfDll;
    setOfDll.insert("RectangleLibrary.dll");
    setOfDll.insert("SquareLibrary.dll");


    // Path to the directory of DLLs
    std::filesystem::path path = std::filesystem::current_path();
    //string exePath = "../../Shape_project/x64/Debug";
    string exePath = path.string();

    /*
    * Loop through all files in the current directory.
    * If found a Shape's DLL that our program can handle, link it to current program
    */
    for (const auto& entry : fs::directory_iterator(exePath)) {
        if (fs::is_regular_file(entry.path())) {
            if (setOfDll.find(entry.path().filename().string()) != setOfDll.end()) {
                string fp = entry.path().filename().string();
                cout << fp << endl;
                getNextDll(factory, exePath, entry.path().filename().string());
            }
        }
    }

    // Read data to list of IShape
    FileReading reader = FileReading("shapes.txt", factory);
    vector<IShape*> shapesList = reader.readFile();
    // Sort list of shape in accending order of their area
    sort(shapesList.begin(), shapesList.end(), compare);
     
    for (int i = 0; i < shapesList.size(); i++) {
        ScreenPrinting::printPerimeterArea(shapesList[i], i + 1);
    }

    system("pause");
    delete factory;
    return 0;
}

void getNextDll(IParserFactory*& factory, string& dir, string dllName) {
    string fullPath = "";
    HRESULT hrReturnVal;
    fullPath = FileHandling::getFullPath(dir, dllName);
    LPCWSTR cur_path = FileHandling::getLPCWSTR(fullPath);
    HINSTANCE lib = LoadLibrary(cur_path);

    if (!lib || lib == NULL) {
        hrReturnVal = ERROR_DELAY_LOAD_FAILED;
    }
    else {
        CREATE_PARSER shapeParser = (CREATE_PARSER)GetProcAddress(lib, "createParser");
        IParser* parser = shapeParser();
        factory->registerWith(parser->to_string(), parser);
    }
}
