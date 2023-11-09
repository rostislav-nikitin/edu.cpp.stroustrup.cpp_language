#include <string>
#include <iostream>

#include "analyzer.h"

int main(int argc, char* argv[])
{
	using namespace analyzer;
	//using analyzer::analyze;
	if(argc < 2)
	{
		std::cerr << "Specify at least one .h/.cpp file to analyse." << std::endl;
		return 1;
	}

	for(int idx = 0; idx < argc; idx++)
	{
		std::string file_name{argv[idx]};
		std::cout << file_name << std::endl;
		analyze(file_name);
	}

	return 0;
}
