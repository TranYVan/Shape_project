#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include "main.h"

/// <summary>
/// Interface for handling the path to DLLs
/// </summary>
class FileHandling {
public:
	/// <summary>
	/// Get the complete path of a DLL
	/// </summary>
	/// <param name="directory"> Name of directory </param>
	/// <param name="file"> Name of DLL file </param>
	/// <returns> Complete path of DLL </returns>
	static string getFullPath(string directory, string file);
public:
	/// <summary>
	/// Cast the path to LPCWSTR in order to use function LoadLibrary(LPCWSTR path)
	/// </summary>
	/// <param name="file"> Complete path of DLL</param>
	/// <returns> The path after casting</returns>
	static LPCWSTR getLPCWSTR(string file);
};

#endif