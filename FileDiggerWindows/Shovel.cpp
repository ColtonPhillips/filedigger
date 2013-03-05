	#include "Shovel.h"

	void Shovel::BeforeDig(string path) {
		std::cout << "Digging..." << std::endl;
	}
	void Shovel::AfterDig(string path) {
		std::cout << "Done Digging..." << std::endl;
	}

	void Shovel::FileFound(string path) {
		std::cout << path << std::endl;
	}

	void Shovel::DirectoryFound(string path) {
		std::cout << path << std::endl;
	}

	void Shovel::AddFilter(string s) {
		filters.push_back(s);
	}