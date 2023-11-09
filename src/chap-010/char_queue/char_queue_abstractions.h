#ifndef CHAR_QUEUE_ABSTRACTIONS_H
#define CHAR_QUEUE_ABSTRACTIONS_H

namespace Queue
{
	class IChar_queue
	{
		public:
			virtual int size() const = 0;

			virtual void enqueue(char element) = 0;
			virtual char dequeue() = 0;
			virtual char peek() = 0;
	};
}

#endif
