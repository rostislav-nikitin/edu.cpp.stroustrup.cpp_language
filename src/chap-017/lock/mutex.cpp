#include <pthread.h>
#include "mutex.hpp"

namespace Concurrency
{
	Mutex::Mutex() : _locked(false)
	{
		pthread_mutex_init(&_mutex, NULL);
	}

	Mutex::~Mutex()
	{
		pthread_mutex_destroy(&_mutex);
	}

	bool Mutex::get_locked() const
	{
		return _locked;
	}

	void Mutex::lock()
	{
		pthread_mutex_lock(&_mutex);
		_locked = true;
	}

	void Mutex::unlock()
	{
		pthread_mutex_unlock(&_mutex);
		_locked = false;
	}
}
