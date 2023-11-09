#ifndef ANALYZER_IMPL_H
#define ANALYZER_IMPL_H

#include <string>
#include <iostream>
#include <fstream>

#include "analyzer.h"

namespace analyzer
{
	const std::string system_include_path {"/usr/include/c++/13/"};

	void analyze(std::string &);
	int get_file_size(std::ifstream &);
	void analyze_source_file(std::string &);

	struct Parse_Result
	{
		int comment_lines_count;
		int code_lines_count;
		int words_count;
	};
 
	Parse_Result parse(std::ifstream &src_file);
}

#endif
