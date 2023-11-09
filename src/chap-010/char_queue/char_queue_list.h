#ifndef CHAR_QUEUE_LIST_H
#define CHAR_QUEUE_LIST_H

#include <stdexcept>
#include <list>
#include "char_queue_abstractions.h"

namespace Queue
{
	class Char_queue_list : public IChar_queue
	{
		private:
			std::list<char> _queue;

		public:
			int size() const override;

			void enqueue(char element) override;
			char dequeue() override;
			char peek() override;
	};
}

#endif
