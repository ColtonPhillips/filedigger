/*
	An interface for a "Shovel" which is used by a "FileDigger".
	
	Shovels are an object which abstracts the execution from the FileDigger
	and moves it to the Shovel when a file is found.  In this way, a 
	programmer could create a specific type of shovel (string searching, 
	file copying, word count, line count, etc) by simply creating an interface
	for execution on events.
	
	Shovel implements a filter option, which improves performance if you know
	the extension of the file types you are interested in
	
	Colton Phillips
*/
	#ifndef SHOVEL_H
	#define SHOVEL_H

	#include <vector>
	#include <iostream>
	#include <string>
	using namespace std;

	class Shovel{
		private:
			//List of file extensions to filter
			vector<string> filters;
		public:
		Shovel() {}
		
		/*
		Interface for execution before any recursive digging has occured
		
		Receives a path to the root directory
		*/
		virtual void BeforeDig(string path);
		
		/*
		Interface for execution after all recursive digging
		has completed
		
		Receives a path to the root directory
		*/
		virtual void AfterDig(string path);

		/*
		Interface for execution when a file has been found which
		
		Receives a path to the file
		*/
		virtual void FileFound(string path);
		
		/*
		Interface for execution when a directory has been found
		
		Receives a path to the directory
		*/
		virtual void DirectoryFound(string path);
		
		/*
		Add's a filter to the recursive search.
		
		e.g. shovel.AddFilter(cpp);
		for an instance shovel of Shovel will create a filter for C++
		file extensions.
		
		If no filters have been added, then all file types will be acceptable
		*/
		void AddFilter(string path);
		
		/*
		Returns the list of file extension filters
		*/
		vector<string> GetFilters() { return filters; };
	};

	#endif