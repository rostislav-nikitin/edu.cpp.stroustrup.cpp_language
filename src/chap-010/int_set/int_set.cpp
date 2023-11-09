#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdarg>

#include "int_set.h"

namespace Set
{
	Int_set::Int_set()
	{
	}

	Int_set::Int_set(int count, ...)
	{
		va_list vl;
		va_start(vl, count);

		while(count--)
		{
			int value = va_arg(vl, int);
			if(!exists(value))
				_set.push_back(value);
		}

		va_end(vl);
	}

	Int_set::Int_set(std::vector<int> set) : _set(set) { }

	bool Int_set::empty() const
	{
		return _set.size() == 0;
	}

	int Int_set::size() const
	{
		return _set.size();
	}

	void Int_set::add(int value)
	{
		if(!exists(value))
			_set.push_back(value);
	}

	void Int_set::remove(int value)
	{
		std::vector<int>::iterator it_found = std::find(_set.begin(), _set.end(), value);
		if(it_found != _set.end())
			_set.erase(it_found);
	}

	bool Int_set::exists(int value)
	{
		std::vector<int>::iterator it_begin = _set.begin();
		std::vector<int>::iterator it_end = _set.end();

		bool value_exists = std::find(it_begin, it_end, value) != it_end;

		return value_exists;
	}	

	Int_set Int_set::uni(Int_set const &set)
	{
		std::vector<int> result_set {set._set};
		std::vector<int>::iterator it_current = _set.begin();
		while(it_current != _set.end())
		{
			if(std::find(result_set.begin(), result_set.end(), *it_current) == result_set.end())
				result_set.push_back(*it_current);

			it_current++;
		}

		Int_set result {result_set};

		return result;
	}

	Int_set Int_set::intersect(Int_set const &set)
	{
		std::vector<int> result_set;

		std::vector<int>::iterator it_current = _set.begin();
		while(it_current != _set.end())
		{
			if(std::find(set._set.begin(), set._set.end(), *it_current) != set._set.end())
				result_set.push_back(*it_current);

			it_current++;
		}

		Int_set result {result_set};

		return result;
	}

	Int_set Int_set::substract(Int_set const &set)
	{
		std::vector<int> result_set;

		std::vector<int>::iterator it_current = _set.begin();
		while(it_current != _set.end())
		{
			if(std::find(set._set.begin(), set._set.end(), *it_current) == set._set.end())
			{
				result_set.push_back(*it_current);
			}
			it_current++;
		}

		Int_set result{result_set};

		return result;
	}

	int Int_set::operator[](int index)
	{
		return _set.at(index);
	}

	void Int_set::print()
	{
		//std::cout << __PRETTY_FUNCTION__ << " Not Implemented" << std::endl;
		int not_first = 0;
		std::cout << "{";
		std::for_each(_set.begin(), _set.end(), [&not_first](int value) { std::cout << (not_first++ ? "," : "") << " " << value;  });
		std::cout << " }" << std::endl;
	}
}
