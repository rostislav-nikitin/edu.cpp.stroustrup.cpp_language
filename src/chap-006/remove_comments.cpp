#include <string>
#include <iostream>
#include <sstream>

// One line comment

float fvar = 10.5; // Post statement comment

int x = 10; /* multiline comment in one line */
int y = 20;
/*
 *  MULTILINE COMMENT
*/
int z = 50;
int main()
{
	std::string line;
	bool mlc = false;
	bool was_mlc = false;
	bool bslash = false;
	bool ast = false;


	while(!getline(std::cin, line).eof())
	{
		std::istringstream chars{line};
		bool slc = false;
		bool dq = false;
		std::string buffer;

		while(!chars.eof())
		{
			char ch = chars.get();

			if(!mlc)
			{
				if(!slc)
				{
					if(ch == '\"')
						dq = !dq;
	
					if(!dq)
					{
						if(bslash)
						{
							switch(ch)
							{
								case '*':
								{
									mlc = true;
									bslash = false;
									buffer.pop_back();
									break;
								}
								case '/':
								{
									slc = true;
									bslash = false;
									buffer.pop_back();
									break;
								}
								default:
								{
									bslash = false;
									break;
								}
							}
						}
						else
						{
							if(ch == '/')
								bslash = true;
						}
						
					}
				}
			}
			else
			{
				if(ch == '*')
				{
					ast = true;
				}
				else if(ast && ch == '/')
				{
					mlc = false;
					ast = false;
					was_mlc = true;
					continue;
				}
				else
				{
					ast = false;
				}
			}


			if(!mlc && !slc && ch != '\n' && ch != '\r' && (ch > 20 || ch == '\t'))
				buffer.push_back(ch);

		}

		if((!mlc && !was_mlc) || !buffer.empty())
			std::cout << buffer << std::endl;

		was_mlc = false;
	}

	return 0;
}
