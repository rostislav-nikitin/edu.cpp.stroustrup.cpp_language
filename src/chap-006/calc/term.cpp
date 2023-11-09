#include "term.h"

extern Token_value curr_token;

double term(bool get)
{
	double left = prim(get);
	for( ; ; )
	{
		switch(curr_token)
		{
			case MUL:
				left *= prim(true);
				break;
			case DIV:
				if(double d = prim(true))
				{
					left /= d;
					break;
				}
				return error(std::string("divide by zero\n\t") + std::string(__FILE__) + std::string(": ") + std::to_string(__LINE__));
			default:
				return left;
		}
	}
}
