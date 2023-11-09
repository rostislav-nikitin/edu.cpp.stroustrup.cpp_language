#include <iostream>
#include <cstdarg>

typedef void(* fnptr_void_int)(int); // ?
typedef void(* fnptr_mouse_click_handler)(int, int); // !

#define PI 3.14;

double pi = PI;

void error(char const *message ...)
{
	va_list va;
	va_start(va, message);

	char c;
	bool sc_started = false;
	while((c = *message++) != '\0')
	{
		if(c == '%')
		{
			if(!sc_started)
				sc_started = true;
			else
				std::cout << c;
		}
		else
		{
			if(sc_started)
			{
				switch(c)
				{
					case 'i':
						std::cout << va_arg(va, int);
						break;
					case 'f':
						std::cout << va_arg(va, double);
						break;
					default:
						std::cout << "%" << c;
						break;
				}
				sc_started = false;
			}
			else
			{
				std::cout << c;
			}
		}
	}

	if(sc_started)
		std::cout << '%';

	va_end(va);
}

int main()
{
	std::cout << "error.cpp" << std::endl;
	error("TEST[%%f]=%%a", 100.5);
	return 0;
}
