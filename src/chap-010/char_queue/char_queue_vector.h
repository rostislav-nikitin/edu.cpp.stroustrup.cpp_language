#ifndef CHAR_QUEUE_VECTOR_H
#define CHAR_QUEUE_VECTOR_H

#include <stdexcept>
#include <vector>

#include "char_queue_abstractions.h"

namespace Queue
{
	class Char_queue_vector : public IChar_queue
	{
		private:
			std::vector<char> _queue;

		public:
			int size() const override;

			void enqueue(char element) override;
			char dequeue() override;
			char peek() override;
	};
}

#endif
