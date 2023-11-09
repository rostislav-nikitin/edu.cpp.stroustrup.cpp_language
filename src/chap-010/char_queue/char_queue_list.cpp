#include "char_queue_list.h"

namespace Queue
{
	int Char_queue_list::size() const
	{
		return _queue.size();
	}

	void Char_queue_list::enqueue(char element)
	{
		//std::cout << __PRETTY_FUNCTION__ << std::endl;
		_queue.push_front(element);
	}

	char Char_queue_list::dequeue()
	{
		//std::cout << __PRETTY_FUNCTION__ << std::endl;
		if(_queue.size() == 0)
			throw std::out_of_range("Out of range exception");

		char result = _queue.front();
		_queue.pop_front();

		return result;
	}

	char Char_queue_list::peek()
	{
		//std::cout << __PRETTY_FUNCTION__ << std::endl;
		if(_queue.size() == 0)
			throw std::out_of_range("Out of range exception");

		return _queue.front();
	}
}
