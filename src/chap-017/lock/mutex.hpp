#ifndef MUTEX_HPP
#define MUTEX_HPP

#include <pthread.h>

namespace Concurrency
{
	class Mutex
	{
		pthread_mutex_t _mutex;
		bool _locked;
	public:
		Mutex();
		~Mutex();

		bool get_locked() const;

		void lock();
		void unlock();
	};
}

#endif
