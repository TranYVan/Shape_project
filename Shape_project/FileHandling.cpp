#include "FileHandling.h"
#include <locale>
#include <codecvt>

string FileHandling::getFullPath(string directory, string file)
{
	string res = directory;
	for (int i = 0; i < res.length(); i++) {
		if (res[i] == '/') {
			res[i] = '\\';
		}
	}
	res += "\\" + file;
	return res;

}

LPCWSTR FileHandling::getLPCWSTR(string file)
{
	int wstrLength = MultiByteToWideChar(CP_UTF8, 0, file.c_str(), -1, nullptr, 0);
	wchar_t* wstr = new wchar_t[wstrLength];
	MultiByteToWideChar(CP_UTF8, 0, file.c_str(), -1, wstr, wstrLength);
	
	LPCWSTR lpcwstr = wstr;
	return lpcwstr;
}
