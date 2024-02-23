#include <cstring>
#include <string>
#include <iostream>
#include <chrono>

template<class T1, class T2>
std::string concat(T1 s1, T2 s2)
{
	std::string result = s1;
	result.append(s2);

	return result;
}

char * cconcat(char const *s1, char const *s2)
{
	size_t result_length = strlen(s1) + strlen(s2) + 1;
	char *result = static_cast<char *>(malloc(result_length * sizeof(char)));

	strcpy(result, s1);
	strcpy(result + strlen(s1), s2);
	result[result_length - 1] = '\0';

	return result;
}

int main()
{
	int const CYCLES = 1000000;
	std::chrono::time_point<std::chrono::system_clock> started = std::chrono::system_clock::now();
	// C++
	for(int i = 0; i < CYCLES; ++i)
	{
		std::string result = concat(concat("file", "."), "write");
	}
	// ~C++
	std::chrono::time_point<std::chrono::system_clock> finished = std::chrono::system_clock::now();
	std::chrono::duration<std::chrono::system_clock::rep, std::chrono::system_clock::period> cpp_elapsed = finished - started;
	std::cout << "C++:\t" << std::chrono::duration_cast<std::chrono::milliseconds>(cpp_elapsed).count() << "ms" << std::endl;

	started = std::chrono::system_clock::now();
	// C
	for(int i = 0; i < CYCLES; ++i)
	{
		char * file_dot = cconcat("file", ".");
		char * file_dot_write = cconcat(file_dot, "write");

		//std::cout << file_dot_write << std::endl;

		free(file_dot_write);
		free(file_dot);
	}
	// ~C
	finished = std::chrono::system_clock::now();
	std::chrono::duration<std::chrono::system_clock::rep, std::chrono::system_clock::period> c_elapsed = finished - started;
	std::cout << "C:\t" << std::chrono::duration_cast<std::chrono::milliseconds>(c_elapsed).count() << "ms" << std::endl;

	std::cout << "Diff:\t" << (std::chrono::duration_cast<std::chrono::milliseconds>(cpp_elapsed).count() - 
			std::chrono::duration_cast<std::chrono::milliseconds>(c_elapsed).count()) << "ms" << std::endl;

	return EXIT_SUCCESS;	
}
