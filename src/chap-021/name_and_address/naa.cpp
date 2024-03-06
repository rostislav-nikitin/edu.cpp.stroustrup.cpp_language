#include <string>
#include <vector>

#include <sstream>
#include <iostream>
#include <iterator>

struct NameAndAddress
{
	std::string name;
	std::string address;
};

std::string encode(std::string const &origin)
{
	std::string result;
	result.reserve(origin.size());

 	for(int idx = 0; idx < origin.length(); ++idx)
	{
		const unsigned char c = origin[idx];
		
		if(c == ' ')
			result.append(1, '%');
		else
			result.append(1, c);
	}

	return result;
}

std::string decode(std::string const &encoded)
{
	std::string result;
	result.reserve(encoded.size());

	for(int idx = 0; idx < encoded.length(); ++idx)
	{
		char unsigned const c = encoded[idx];
		if(c == '%')
			result.append(1, ' ');
		else
			result.append(1, c);
	}

	return result;
}

std::ostream &operator<<(std::ostream &stream, NameAndAddress const &value)
{
	
	stream << encode(value.name) << ";" << encode(value.address) << ".";

	return stream;
}

std::istream &operator>>(std::istream &stream, NameAndAddress &value)
{
    int state = 0;
	
	unsigned char sym;
	std::string buffer;
	buffer.reserve(64);

	//	std::cout << __PRETTY_FUNCTION__ << std::endl;
	
	while(stream >> sym)
	{
		//std::cout << sym;
		if(sym == ';')
		{
			value.name = decode(buffer);
			//std::cout << value.name << std::endl;
			buffer.clear();
			++state;
		}
		else if(sym == '.')
		{
			value.address = decode(buffer);
			buffer.clear();
			//std::cout << value.address << std::endl;
			++state;
			break;
		}
		else
	    {
			buffer.append(1, sym);
		}
	}
	
	if(!buffer.empty())
	{
		if(state == 0)
			value.name = decode(buffer);
		else if(state == 1)
			value.address = decode(buffer);
	}

	return stream;
}

int main()
{
	std::vector<NameAndAddress> naas({{"John Doe", "USA, New York, Baker Street 38/1"}, {"Mike Smith", "USA, New York, 5th ave/38"}});
  
	std::stringstream in_naa;
	std::copy(naas.begin(), naas.end(), std::ostream_iterator<NameAndAddress>(in_naa));
	in_naa.seekg(0, std::ios_base::beg);

	NameAndAddress naa;
	while(in_naa >> naa)
	{
		std::cout << naa << std::endl;
	}
	
	//	in_naa << naa1 << std::endl;
}
