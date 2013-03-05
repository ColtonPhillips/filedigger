	#include "FileDigger.h"
	#include "SearchShovel.h"
	#include <iostream>
	#include <windows.h>
	#include <fstream>

	void FileDigger::Dig(string directory, Shovel& shovel) {
		shovel.BeforeDig(directory);
		DigForFiles(directory, shovel);
		shovel.AfterDig(directory);
	}

	void FileDigger::DigForFiles (string directory, Shovel& shovel) {
		WIN32_FIND_DATA ffd; //Find File Data
		HANDLE hFind;

		directory.append("\\");

		string tempdir = directory;
		tempdir.append("*");

		hFind = FindFirstFile(tempdir.c_str(), &ffd); 	//  .  directory
		FindNextFile(hFind, &ffd);						//  .. directory

		while (FindNextFile(hFind, &ffd) !=0 ) {

			string currFileString = directory;
			currFileString.append(ffd.cFileName);

			if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { // File is a directory
				shovel.DirectoryFound(currFileString);
				DigForFiles(currFileString, shovel);

			}
			// Are no filters, or is Filter word
			else if (shovel.GetFilters().empty() || isFilterType(currFileString, shovel.GetFilters()) ) {
				shovel.FileFound(currFileString);
			}
		}
		return;
	}

	bool FileDigger::hasEnding(const string& fullString, const string& ending) {
		if (fullString.length() > ending.length()) {
			return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending) );
		}
		else {
			return false;
		}
	}

	bool FileDigger::isFilterType(const string& path, const vector<string>& filters) {
		for (int i = 0; i < filters.size(); i++) {
			if ( hasEnding(path, filters[i]) ){
				return true;
			}
		}
		return false;
	}

	int main(int argc, char *argv[]) {

		if( argc < 2 ) {
			cout << "Not enough arguments:\n\n Ex: a C:\\cpp\\a cpp h";
			return 1;
		}

		FileDigger f;
		SearchShovel s("poop");
		string directory = argv[1];

		// Get filters from arguments
		for (int i = 2; i < argc; i++) {
			s.AddFilter(argv[i]);
		}

		f.Dig(directory, s);
		return 0;
	}