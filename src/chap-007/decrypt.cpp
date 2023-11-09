#include <fstream>
#include <iostream>
#include <cstdlib>

const int Key_Size = 16;
char key[Key_Size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

int main(int argc, char *argv[])
{
	if(argc < 2)
		return 0;
	std::string file_name {argv[1]};

	std::ifstream fstream{file_name};
	char c;
	int idx = 0;
	char buffer[32];
	int buffer_idx = 0;
	while((c = fstream.get()) != std::string::npos)
	{
		if(c != ' ')
		{
			buffer[buffer_idx++] = c;
		}
		else
		{
			buffer[buffer_idx] = '\0';
			std::cout << static_cast<char>(atoi(buffer) ^ key[idx++]);
			buffer_idx = 0;
			if(idx >= Key_Size)
				idx = 0;
		}

	}

	std::cout << "END" << std::endl;
	return 0;
}
