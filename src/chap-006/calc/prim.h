#ifndef __PRIM_H__
#define __PRIM_H__

#include <string>
#include <map>

#include "token.h"
#include "expr.h"

struct Symbol
{
	std::string string_value;
	double number_value;
};

double prim(bool get);

#endif
