#include "expr.h"

extern Token_value curr_token;

double expr(bool get)
{
	double left = term(get);

	for( ; ; )
	{
		switch(curr_token)
		{
			case PLUS:
				left += term(true);
				break;
			case MINUS:
				left -= term(true);
				break;
			default:
				return left;
		}
	}
}
