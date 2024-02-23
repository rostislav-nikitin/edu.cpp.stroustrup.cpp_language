#include <iostream>
#include <iterator>

class BackInsertCharIterator : public std::iterator<std::output_iterator_tag, char>
{
	size_t _pos;
	std::string &_container;
public:
	BackInsertCharIterator(std::string &container);

	BackInsertCharIterator &operator=(char value);
	BackInsertCharIterator &operator*();
	BackInsertCharIterator operator++();
};

BackInsertCharIterator::BackInsertCharIterator(std::string &container) : _container(container), _pos(0)
{
}

BackInsertCharIterator &BackInsertCharIterator::operator=(char value)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	//std::cout << value << std::endl;
	if(_container.size() == _pos)
	{
		_container.append(1, value);
	}
	else if(_container.size() < _pos)
	{
		_container.resize(_pos, 'x');
		_container[_pos] = value;
	}
	else
	{
		_container[_pos] = value;
	}

	return *this;
}
BackInsertCharIterator &BackInsertCharIterator::operator*()
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	return *this;
}
BackInsertCharIterator BackInsertCharIterator::operator++()
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	BackInsertCharIterator temp = *this;
	++_pos;

	return temp;
}

BackInsertCharIterator BackInserter(std::string &s)
{
	return BackInsertCharIterator(s);
}

int main()
{
	std::string original = "Original string...";
	std::string target;

	std::copy(original.begin(), original.end(), BackInserter(target));

	std::cout << "Original: \t" << original << std::endl;
	std::cout << "Target: \t" << target << std::endl;

	return EXIT_SUCCESS;
}
