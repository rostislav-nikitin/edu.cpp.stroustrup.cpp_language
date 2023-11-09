#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

struct Word
{
	std::string word;
	float sum;
	int count;
	std::vector<float> values;
};

std::vector<Word> words;


void add_word(std::string &word, float number)
{
	std::vector<Word>::iterator it_begin = words.begin();
	std::vector<Word>::iterator it_end = words.end();

	std::vector<Word>::iterator found = std::find_if(it_begin, it_end, [word](Word &list_word) { return list_word.word == word; });
	if(found != it_end)
	{
		std::cout << "FOUND" << std::endl;
		found->sum += number;
		found->count++;
		found->values.push_back(number);
	}
	else
	{
		std::cout << "NOT FOUND" << std::endl;
		words.push_back(Word{word, number, 1, {number}});
	}

}


float get_sum()
{
	float sum = 0;

	for(int idx = 0; idx < words.size(); idx++)
	{
		sum += words[idx].sum;
	}

	return sum;
}

float get_count()
{
	float count = 0;

	for(int idx = 0; idx < words.size(); idx++)
	{
		count += words[idx].count;
	}

	return  count;
}

float get_avg()
{
	float sum = 0, count = 0;

	for(int idx = 0; idx < words.size(); idx++)
	{
		sum += words[idx].sum;
		count += words[idx].count;
	}

	return sum / count;
}

float get_median(Word &word)
{
	float result = 0;
	std::vector<float> &values = word.values;

	std::sort(values.begin(), values.end());

	if(values.size() == 0)
	{
		result = 0.0;
	}
	else if(values.size() == 1)
	{
		result = values[0];
	}
	else if(values.size() % 2 == 1)
	{
		result = values[values.size() / 2];
	}
	else
	{
		result = (values[values.size() / 2 - 1] + values[values.size() / 2]) / 2.0;
	}

	return result;
}

void print_words()
{
	std::for_each(words.begin(), words.end(), [](Word &word) { std::cout << word.word << "\tSum: " << word.sum  << "\tAvg: " << word.sum / word.count << "\tMedian: " << get_median(word) << std::endl; });
}

void print_totals()
{
	std::cout << "Totals" << std::endl << "\tSum: " << get_sum() << "\tAvg: " << get_avg() << std::endl;
}


int main()
{

	std::string input;

	getline(std::cin, input);
	std::cout << input << std::endl;

	std::istringstream input_stream {input};

	while(!input_stream.eof())
	{
		std::string word;
		input_stream >> word;
		float number;
		input_stream >> number;
		std::cout << word << ":" << number << std::endl;
		add_word(word, number);
	}

	print_words();
	print_totals();
	
/*
	int x = 5;
	int y = 0;
	int z = x / y;
	std::cout << z << std::endl;
*/
/*
	char *letters = "ABCDEFG";
	char *it_letter = letters;
	while(*it_letter != '\0')
	{
		std::cout << *it_letter++ << std::endl;
	}
*/
	return 0;
}
