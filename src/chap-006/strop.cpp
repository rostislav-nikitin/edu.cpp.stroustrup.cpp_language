#include <iostream>

unsigned int strlen(char const *in_str)
{
	int result = 0;
	while(*in_str++ != '\0')
		result++;

	return result;
}

void strcpy(char const *source, char *destination, unsigned int length = -1)
{
	while(*source != '\0' && (length < 0 || length--))
		*destination++ = *source++;
	*destination = '\0';
}

bool strcmp(char const *str1, char const *str2)
{
	while(*str1 != '\0' && *str2 != '\0')
	{
		if(*str1++ != *str2++)
			return false;
	}

	return *str1 == *str2;
}

char *cat(char const *str1, char const *str2)
{
	int str1_length = strlen(str1);
	int str2_length = strlen(str2);
	int result_length = str1_length + str2_length + 1;
	char *result = new char[result_length];
	strcpy(str1, result);
	strcpy(str2, result + str1_length);

	return result;
}

void rev(char *str)
{
	int str_len = strlen(str);

	for(int idx = 0; idx < str_len / 2; idx++)
	{
		int left_idx = idx;
		int right_idx = str_len - idx - 1;

		char temp = str[left_idx];
		str[left_idx] = str[right_idx];
		str[right_idx] = temp;
	}
}

int atoi(char const *str)
{
	int result = 0;

	int str_len = strlen(str);
	bool sign = false;
	int base = 10;
	int start_idx = 0;
      	if(str_len > 1 && str[0] == '0' && str[1] == 'x')
	{
		base = 16;
		start_idx = 2;
	}
	else if(str_len > 0 && str[0] == '0')
	{
		base = 8;
		start_idx = 1;
	}
	else if(str_len > 0 && str[0] == '-')
	{
		sign = true;
	}
	int mul = 1;

	for(int idx = str_len - 1; idx >= start_idx; idx--)
	{
		if(base == 8 && (str[idx] < '0' || str[idx] > '8'))
			continue;
		if(base == 10 && (str[idx] < '0' || str[idx] > '9'))
			continue;
		if(base == 16 && !((str[idx] >= '0' && str[idx] <= '9') || (str[idx] >= 'a' && str[idx] <= 'f') ))
			continue;

		char digit = 0;

		if(str[idx] >= '0' && str[idx] <= '9')
			digit = str[idx] - '0';

		if(str[idx] >= 'a' && str[idx] <= 'f')
			digit = str[idx] - 'a' + 10;

		result += digit * mul;
		mul *= base;
	}

	result *= sign ? -1 : 1;
	
	return result;
}

void itoa(int i, char out[])
{
	int idx = 0;
	bool neg = i < 0;
	i = neg ? -i : i;

	do
	{
		int reminder = i % 10;
		out[idx++] = '0' + reminder;
		i = i / 10;
	}
	while(i);

	if(neg)
		out[idx++] = '-';

	out[idx] = '\0';
	rev(out);
}

int main()
{
	char const *test_string = "abcd efgh";
	char dest_string[10];
	char const *some_string = "xyz";

	unsigned int str_length = strlen(test_string);

	std::cout << str_length << std::endl;
	strcpy(test_string, dest_string);

	std::cout << dest_string << std::endl;
	std::cout << strcmp(test_string, dest_string) << std::endl;
	std::cout << strcmp(test_string, some_string) << std::endl;

	char *con = cat(test_string, some_string);
	std::cout << con << std::endl;

	delete[] con;

	rev(dest_string);
	std::cout << dest_string << std::endl;

	char buffer[63];
	itoa(-504, buffer);

	std::cout << buffer << std::endl;
	
	std::cout << atoi("-553") << std::endl;
	std::cout << atoi("0xff") << std::endl;
	std::cout << atoi("081") << std::endl;

	


	return 0;
}
