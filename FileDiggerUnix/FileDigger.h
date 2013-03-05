/*

FileDigger is a program which takes a directory as input and recursively navigates through all subdirectories
and calls executions on files/directories.  FileDigger takes a Shovel as input, which is used to abstract operations
on the directories and files visited during the recursive navigation.  A user can implement an interface of the
Shovel class in order to accomplish tasks such as word count, word searching, copying files, etc, relelatively easy
and in a clear and concise format.

An example of the implementation of FileDigger as well as a Shovel can be seen in the main() function of FileDigger

Compiled using mingw

FileDigger uses the Windows API, thus will only work on windows platforms.


Author: Colton Phillips

*/

	#ifndef FILEDIGGER_H
	#define FILEDIGGER_H

	#include <vector>
	#include <string>
	#include "Shovel.h"
	using namespace std;

	class FileDigger {

		public:
		FileDigger() {}

		/*
		Public member function Dig is called by user of FileDigger function in order to initialize the
		recursive execution process.  Dig takes a string path to the root directory to search in, as well
		as a Shovel which will be used on execution of files/directories
		*/
		void Dig(string directory, Shovel& shovel);

		private:

		/*
		The actual recursive function which is called on directory to path.  This function is called by public
		member function Dig, after calling Shovel function shovel.BeforeDig(), and before calling shovel.AfterDig()
		*/
		void DigForFiles(string directory, Shovel& shovel);

		/*
		Returns true if fullString has ending appended to the end of it. This is used to determine if
		fullstring contains the appropriate file type extension determined by the filters attached to the Shovel
		class
		*/
		bool hasEnding(const string& fullString, const string& ending);

		/*
		Returns true if path ends with one of the file type extensions contained in filter vector
		*/
		bool isFilterType(const string& path, const vector<string>& filters);

	};

	#endif