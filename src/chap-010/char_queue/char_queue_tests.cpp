#include "char_queue_tests.h"

void Queue::Tests::test(Queue::IChar_queue &queue)
{
	std::cout << "Queue size: " << queue.size() << std::endl << std::endl;

	std::cout << "Enqueue 'A'" << std::endl;      
	queue.enqueue('A');
	std::cout << "Queue size: " << queue.size() << std::endl << std::endl;

	std::cout << "Peek: '" << queue.peek() << "'" << std::endl;
	std::cout << "Queue size: " << queue.size() << std::endl << std::endl;

	std::cout << "Dequeue: '" << queue.dequeue() << "'" << std::endl;
	std::cout << "Queue size: " << queue.size() << std::endl << std::endl;

	try
	{
		std::cout << "Dequeue: '" << queue.dequeue() << "'" << std::endl;
	}
	catch(std::out_of_range ex)
	{
		std::cout << "Out of range exception" << std::endl;
	}
	std::cout << "Queue size: " << queue.size() << std::endl;
}
