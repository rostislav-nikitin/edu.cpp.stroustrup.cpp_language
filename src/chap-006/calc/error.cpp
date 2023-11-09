#include "error.h"

int no_of_errors;

double error(std::string const &error_message)
{
	no_of_errors++;
	std::cerr << "error: " << error_message << std::endl;
	return 1;
}
