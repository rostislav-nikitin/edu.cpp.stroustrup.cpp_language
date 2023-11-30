#include <iostream>
#include <atomic>

class AlreadyLockedException : public std::exception { };

class Mutex
{
	std::atomic<bool> _locked;

	public:
		Mutex() : _locked(false) {}

		void lock()
		{
			bool expected = false;
			if(!_locked.compare_exchange_weak(expected, true))
			{
				throw AlreadyLockedException();
			}
		}
		void unlock()
		{
			_locked.store(false);
		}
};

class Lock
{
	Mutex &_mutex;
public:
	Lock(Mutex &mutex) : _mutex(mutex)
	{
		_mutex.lock();
		std::cout << "Mutex [LOCKED]" << std::endl;
	}

	virtual ~Lock()
	{
		_mutex.unlock();
		std::cout << "Mutex [UNLOCKED]" << std::endl;
	}
};

Mutex mtx;

int main()
{
	// Lock
	{
		Lock lock(mtx);
		try
		{
			Lock lock2(mtx);
		}
		catch(AlreadyLockedException &alex)
		{
			std::cout << "Can not aciquire lock, because resource already locked." << std::endl;
		}
	}
	
	try
	{
		Lock lock2(mtx);
	}
	catch(AlreadyLockedException &alex)
	{
		std::cout << "Can not aciquire lock, because resource already locked" << std::endl;
	}

	return 0;
}
