#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>
#include <iostream>
#include <sstream>
#include <cctype>

#include "prim.h"
#include "error.h"

enum Token_value
{
	NAME,		NUMBER,		END,
	PLUS='+',	MINUS='-',	MUL='*', 	DIV='/',
	PRINT=';',	ASSIGN='=',	LP='(',		RP=')'

};

Token_value get_token();

#endif
