#include <iostream>
#include "mutex.hpp"

int main()
{
	using Concurrency::Mutex;

	Mutex mutex;

	mutex.lock();
	std::cout << "Locked=" << mutex.get_locked() << std::endl;
	mutex.unlock();
	std::cout << "Locked=" << mutex.get_locked() << std::endl;

	return EXIT_SUCCESS;
}
