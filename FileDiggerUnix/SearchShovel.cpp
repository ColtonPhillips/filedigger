	#include "SearchShovel.h"
	#include <fstream>
	#include <iostream>

	void SearchShovel::BeforeDig(string path) {
		cout << "Searching Files..." << endl;
	}

	void SearchShovel::AfterDig(string path) {
		cout << "Finished..." << endl;
	}

	void SearchShovel::FileFound(string path) {
		ifstream file;
		file.open(path.c_str());

		string temp;

		bool quit = false;
		while(getline(file, temp)) {
			if (string::npos != temp.find(search_string)) {
				cout << path << endl;
				break;
			}

		}
		file.close();
	}

	void SearchShovel::DirectoryFound(string path) {
	}
