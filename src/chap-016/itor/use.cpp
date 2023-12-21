#include <iostream>

#include "vector_abstractions.hpp"
#include "list_abstractions.hpp"

template<class T>
void show(Containers::Itor<T> &&itor)
{
	int idx = 0;
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	for(T *current = itor.first(); current != nullptr; current = itor.next())
	{
		std::cout << *current << std::endl;
	}
}

int main()
{
	using Containers::Vector;
	using Containers::VectorItor;

	Vector<int> evens(10);
	evens.push_back(6);
	evens.push_back(2);
	evens.push_back(4);

	Vector<int> empty(4);
	//empty.push_back(1);
	show(VectorItor<int>(evens));
	show(VectorItor<int>(empty));

	using Containers::List;
	using Containers::ListItor;

	List<int> odds;
	odds.put(5);
	odds.put(1);
	odds.put(3);

	show(ListItor<int>(odds));

	return 0;
}
