#ifndef INT_SET_H
#define INT_SET_H

#include <vector>

namespace Set
{
	class Int_set
	{
		private:
			std::vector<int> _set;

		public:
			Int_set();
			Int_set(int count, ...);
			Int_set(std::vector<int> set);
	
			bool empty() const;
			int size() const;

			void add(int value);
			void remove(int value);
			bool exists(int value);

			Int_set uni(Int_set const &set);
			Int_set intersect(Int_set const &set);
			Int_set substract(Int_set const &set);

			int operator[](int index);

			void print();
	};
}

#endif
