#include "analyzer_impl.h"

void analyzer::analyze(std::string &file_name)
{
	std::cout << "\t" << "includes" << std::endl;
	std::ifstream input {file_name};
	char line[1024];
	while(input.getline(line, 1024))
	{
		std::string str_line{line};
		std::string inc_string = "#include <";
		size_t inc_string_len = inc_string.size();
		size_t pos_start = str_line.find(inc_string);
		if(pos_start != std::string::npos)
		{
			size_t pos_end = str_line.find(">", inc_string_len + pos_start);

			if(pos_end != std::string::npos)
			{
				size_t len = pos_end - (pos_start + inc_string_len);
				if(len > 0)
				{
					std::string inc_file_name = str_line.substr(inc_string_len + pos_start, len);
					std::string inc_file_path = system_include_path + inc_file_name;
					analyze_source_file(inc_file_path);
				}
			}
		}
		
	}
}

void analyzer::analyze_source_file(std::string &inc_file_path)
{

	std::cout << "\t" << inc_file_path << std::endl;

	std::ifstream inc_file {inc_file_path};
	{
		int inc_file_len = get_file_size(inc_file);
		Parse_Result pres = parse(inc_file);
		std::cout << "\t\tSize: " << inc_file_len << "\tComment lines: " << pres.comment_lines_count << "\tCode lines: " << pres.code_lines_count << "\tWords count: " << pres.words_count << std::endl;

		inc_file.close();
	}
}

int analyzer::get_file_size(std::ifstream &inc_file)
{
	inc_file.seekg(0, inc_file.end);
	int result = inc_file.tellg();
	inc_file.seekg(0, inc_file.beg);

	return result;
}

analyzer::Parse_Result analyzer::parse(std::ifstream &src_file)
{
	
	Parse_Result result{0, 0, 0};

	char src_file_line[1024];
	while(src_file.getline(src_file_line, 1024))
	{
		std::string str_line {src_file_line};
		if(str_line.find("//") != std::string::npos)
		{
			result.comment_lines_count++;
		}
		else
		{
			result.code_lines_count++;
			bool ws = false;
			for(int idx = 0; idx < str_line.size(); idx++)
			{
				if(!ws)
				{
					if (isalpha(str_line[idx]))
					{
						result.words_count++;
						ws = true;
					}
				}
				else
				{
					if(str_line[idx] == ' ')
						ws = false;
				}
			}

		}
		

	}

	return result;
}
