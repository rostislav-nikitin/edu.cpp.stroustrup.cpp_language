#include "tests.h"

int main()
{
	std::cout << "TEST CHAR QUEUE :: LIST" << std::endl;

	using Queue::Char_queue_list;

	Char_queue_list queue_list;
	Queue::Tests::test(queue_list);

	std::cout << std::endl;

	std::cout << "TEST CHAR QUEUE :: VECTOR" << std::endl;

	using Queue::Char_queue_vector;

	Char_queue_vector queue_vector;
	Queue::Tests::test(queue_vector);
	
	return 0;
}
