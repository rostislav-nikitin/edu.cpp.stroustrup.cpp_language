#ifndef ITOR_ABSTRACTIONS_H
#define ITOR_ABSTRACTIONS_H

#include <memory>

namespace Containers
{
	//Iterator interface
	template<class T>
	class Itor
	{
	public:
		virtual T *first() = 0;
		virtual T *next() = 0;
	};
	
	template<class T>
	class ReverseItor : public Itor<T>
	{
	public:
		virtual std::unique_ptr<Itor<T>> get_base() = 0;
	};
}
#endif
