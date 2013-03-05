/*
	An example which implements the Shovel interface.
	
	This example shows how with little effort, and how clean and readable it is
	to create a useful extension of the Shovel class with new implementation, 
	as well as overriding virtual functions
*/

	#ifndef SEARCHSHOVEL_H
	#define SEARCHSHOVEL_H

	#include <string>
	#include "Shovel.h"
	using namespace std;

	class SearchShovel : public Shovel {
		private:
			string search_string;
		public:
			SearchShovel(string s = "") : search_string(s) {}

			void BeforeDig(string path);
			void AfterDig(string path);
			void FileFound(string path);
			void DirectoryFound(string path);
	};


	#endif