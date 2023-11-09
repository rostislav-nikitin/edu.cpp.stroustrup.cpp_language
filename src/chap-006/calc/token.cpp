#include "token.h"

Token_value curr_token = PRINT;
extern Symbol symbol;
extern std::istream *input;

Token_value get_token()
{
	char ch;

	do
	{
		if(!input->get(ch))
			return curr_token = END;
	}
	while(ch != '\n' && isspace(ch));

	switch(ch)
	{
		case '*':
		case '/':
		case '+':
		case '-':
		case '(':
		case ')':
		case '=':
			return curr_token = Token_value(ch);
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '.':
			input->putback(ch);
			*input >> symbol.number_value;
			return curr_token = NUMBER;
		case ';':
		case '\n':
			return curr_token = PRINT;
		default:
			if(isalpha(ch))
			{
				symbol.string_value=ch;
				while(input->get(ch) && isalnum(ch)) 
					symbol.string_value.push_back(ch);
				input->putback(ch);
				return curr_token = NAME;
			}
			error(std::string("bad token\n\t") + std::string(__FILE__) + std::string(": ") + std::to_string(__LINE__));
			return curr_token = PRINT;
	}
}
