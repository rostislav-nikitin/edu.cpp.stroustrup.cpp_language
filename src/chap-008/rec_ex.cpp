#include <string>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>

const int Exception_Generation_Depth_Level = 1000;

struct Custom_Exception
{
	std::string fn_name;
	int depth_level;
};

void fn_a(int);
void fn_b(int);

int fn_a_noex(int);
int fn_b_noex(int);

void fn_a(int depth_level = 1)
{
	std::string str = "Some dummy string number one";
	try
	{
		if(depth_level >= Exception_Generation_Depth_Level)
			throw Custom_Exception{std::string(__PRETTY_FUNCTION__)};

		fn_b(++depth_level);
	}
	catch(Custom_Exception ex)
	{
		ex.depth_level++;
		throw ex;		
	}
}

void fn_b(int depth_level = 1)
{
	std::string str = "Some dummy string number one";
	try
	{
		if(depth_level >= Exception_Generation_Depth_Level)
			throw Custom_Exception{std::string(__PRETTY_FUNCTION__)};

		fn_a(++depth_level);
	}
	catch(Custom_Exception ex)
	{
		ex.depth_level++;
		throw ex;		
	}
}

int fn_a_noex(int depth_level = 1)
{
	if(depth_level >= Exception_Generation_Depth_Level)
		return depth_level;

	return fn_b_noex(++depth_level);
}

int fn_b_noex(int depth_level = 1)
{
		if(depth_level >= Exception_Generation_Depth_Level)
			return depth_level;

		return fn_a_noex(++depth_level);
}

int main()
{
	using namespace std::literals;

	std::cout << "RECURSIVE CALLS :: EX" << std::endl;

	Custom_Exception cex;

	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	try
	{
		fn_a();
	}
	catch(Custom_Exception ex)
	{
		cex = ex;
	}
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();

	std::cout << "Exception raised at " << cex.depth_level << " depth level in the " << cex.fn_name << std::endl;
	std::cout << "Time elapsed " << (end - start) / 1us  << std::endl;

	
	std::cout << std::endl;
	std::cout << "RECURSIVE CALLS :: NO EX" << std::endl;
	
	start = std::chrono::system_clock::now();
	int depth_level_noex = fn_a_noex();
	std::cout << "Exception raised at " << depth_level_noex << " depth level in the " << std::endl;
	end = std::chrono::system_clock::now();
	std::cout << "Time elapsed " << (end - start) / 1us  << std::endl;

	return 0;
}
