/*
	An example which implements the Shovel interface.
	
	This example illustrates an implementation of the Shovel class.
	File operations are located in this class, and abstracted from the FileDigger.
*/

	#ifndef LINECOUNTSHOVEL_H
	#define LINECOUNTSHOVEL_H

	#include <string>
	#include "Shovel.h"
	using namespace std;

	class LineCountShovel : public Shovel {
		private:
			int lineCount;
		public:
			LineCountShovel() {}

			virtual void BeforeDig(string path);
			virtual void AfterDig(string path);

			virtual void FileFound(string path);
			virtual void DirectoryFound(string path);

			int LineCounter(string path);
	};


	#endif