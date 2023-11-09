#include <iostream>

void print_ascii_range_inline(unsigned char start_char, int count);
void print_ascii_range_with_code(unsigned char start_char, int count);

int main()
{
	char const first_digit = '0';
	print_ascii_range_with_code(first_digit, 10);

	char const first_char = 'a';
	print_ascii_range_with_code(first_char, 26);

	unsigned char const another_first_char = ' ';
	print_ascii_range_with_code(another_first_char, 255 - 32 + 1);
}

void print_ascii_range_inline(unsigned char start_char, int count)
{

	for(int idx = 0; idx < count; ++idx)
	{
		std::cout <<  start_char++ << "\t";
	}
	std::cout << std::endl;

}

void print_ascii_range_with_code(unsigned char start_char, int count)
{

	for(int idx = 0; idx < count; ++idx)
	{
		std::cout << start_char << "\t - \t" << std::dec << int(start_char) << "\t - \t0x" << std::hex << int(start_char) << std::endl;
		start_char++;
	}
	std::cout << std::endl;
}
