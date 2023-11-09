#include "main.h"

std::istream *input; 

extern int no_of_errors;
extern std::map<std::string, double> table;
extern Token_value curr_token;

int main(int argc, char *argv[])
{
	switch(argc)
	{
		case 1:
			input = &std::cin;
			break;
		case 2:
			input = new std::istringstream(argv[1]);
			break;
		default:
			error(std::string("Too many parameters\n\t") + std::string(__FILE__) + std::string(": ") + std::to_string(__LINE__));
			return 1;
	}

	table["pi"] = 3.14149;
	table["e"] =  2.71828;

	while(!input->eof())
	{
		get_token();
		if(curr_token == END) break;
		if(curr_token == PRINT) continue;

		std::cout << expr(false) << std::endl;
	}

	if(input != &std::cin) delete input;

	return no_of_errors;
}


