#include "char_queue_vector.h"

namespace Queue
{
	int Char_queue_vector::size() const
	{
		return _queue.size();
	}

	void Char_queue_vector::enqueue(char element)
	{
		//std::cout << __PRETTY_FUNCTION__ << std::endl;
		_queue.push_back(element);
	}

	char Char_queue_vector::dequeue()
	{
		//std::cout << __PRETTY_FUNCTION__ << std::endl;
		char result = peek();
		_queue.pop_back();

		return result;
	}

	char Char_queue_vector::peek()
	{
		//std::cout << __PRETTY_FUNCTION__ << std::endl;
		return	_queue.at(_queue.size() - 1);
	}
}
