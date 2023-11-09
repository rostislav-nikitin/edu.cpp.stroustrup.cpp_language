#include <iostream>
#include <cstring>

int original_for_loop_fn(char const *input_line)
{
	int quest_count = 0;

	for(int i = 0; i < strlen(input_line); i++)
		if(input_line[i] == '?')
			quest_count++;

	return quest_count;
}

int while_loop_fn(char const *input_line)
{
	int i = int(), result = int();

	while(i < strlen(input_line))
	{
		if(input_line[i++] == '?')
			result++;
	}

	return result;
}

int while_loop_w_ptr_fn(char const *input_line)
{
	int result = int();

	while(*input_line != '\0')
	{
		if(*input_line++ == '?')
			result++;
	}

	return result;
}

int main()
{
	char *input_string = "Hello, how are you???";
	std::cout << "Results:" << std::endl 
		<< "\tFor: " << original_for_loop_fn(input_string) << std::endl
		<< "\tWhile: " << while_loop_fn(input_string) << std::endl
		<< "\tWhile with pointer: " << while_loop_w_ptr_fn(input_string) << std::endl;
	return 0;
}
