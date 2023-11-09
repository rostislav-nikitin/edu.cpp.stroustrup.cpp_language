#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	for(int idx = 1; idx < argc; idx++)
	{
		std::ifstream file(argv[idx]);
		while(!file.eof())
		{
			int int_out = file.get();
			char out = static_cast<char>(int_out);
			if(out != std::string::npos)
				std::cout << out;
		}
		file.close();
	}
	return 0;
}
