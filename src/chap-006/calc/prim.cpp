#include "prim.h"

extern Token_value curr_token;

Symbol symbol;

std::map<std::string, double> table;

double prim(bool get)
{
	if(get)
		get_token();

	switch(curr_token)
	{
		case NUMBER:
		{
			double value = symbol.number_value;
			get_token();
			return value;
		}
		case NAME:
		{
			double &value = table[symbol.string_value];
			if(get_token() == ASSIGN)
				value = expr(true);
			return value;
		}
		case MINUS:
		{
			return -prim(true);
		}
		case LP:
		{
			double value = expr(true);
			if(curr_token != RP)
				return error(std::string("')' expected\n\t") + std::string(__FILE__) + std::string(": ") + std::to_string(__LINE__));
			get_token();
			return value;
		}
		default:
		{
			return error(std::string("primary expected\n\t") + std::string(__FILE__) + std::string(": ") + std::to_string(__LINE__));
		}

	}
}



