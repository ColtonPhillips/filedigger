	#include "LineCountShovel.h"
	#include <fstream>
	#include <iostream>

	void LineCountShovel::BeforeDig(string path) {
		std::cout << "Initiating Line Counter..." << std::endl;
		lineCount = 0;
	}
	void LineCountShovel::AfterDig(string path) {
		std::cout << "Line Count is " << lineCount << std::endl;
	}

	void LineCountShovel::FileFound(string path) {
		int temp = LineCounter(path);
		lineCount += temp;
		std::cout << path << " " << temp << std::endl;
	}

	void LineCountShovel::DirectoryFound(string path) {
	}


	int LineCountShovel::LineCounter(string path) {
		ifstream file;
		file.open(path.c_str());

		string temp;
		int i = 0;

		while(getline(file, temp)) {
				++i;

		}
		file.close();
		return i;
	}