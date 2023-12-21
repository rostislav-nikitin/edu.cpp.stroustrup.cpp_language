#ifndef ITOR_ABSTRACTIONS_H
#define ITOR_ABSTRACTIONS_H

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
}
#endif
