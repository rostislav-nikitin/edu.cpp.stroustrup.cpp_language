#include <iostream>

#include "vector_abstractions.hpp"
#include "list_abstractions.hpp"


//Decalre functions
template<class T>
void show(Containers::Itor<T> &&itor);

template<class T>
void show(Containers::Itor<T> &itor);

template<class T>
void show(Containers::Itor<T> *itor);

//Define functions
template<class T>
void show(Containers::Itor<T> &&itor)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	show(&itor);
}

template<class T>
void show(Containers::Itor<T> &itor)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	show(std::move(itor));
}

template<class T>
void show(Containers::Itor<T> *itor)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	
	for(T *current = itor->first(); current != nullptr; current = itor->next())
	{
		std::cout << *current << std::endl;
	}
}


int main()
{
	using Containers::Itor;
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
	VectorItor<int> lvalue_empty(empty);
	show(lvalue_empty);
	
	//Reverse itor
	std::cout << "Reverse" << std::endl;
	using Containers::VectorReverseItor;
	show(VectorReverseItor<int>(evens));
	// Base itor
	std::cout << "Base" << std::endl;
	show(reinterpret_cast<Itor<int>&&>(*VectorReverseItor<int>(evens).get_base()));

	using Containers::List;
	using Containers::ReadOnlyListItor;
	using Containers::ReadOnlyListReverseItor;

	int x = 5;
	int y = 1;
	int z = 3;
	List<int> odds;
	odds.put(&x);
	odds.put(&y);
	odds.put(&z);
	std::cout << "Added" << std::endl;

	ReadOnlyListItor<int> it = ReadOnlyListItor<int>(odds);
	show(it);

	ReadOnlyListReverseItor<int> rit = ReadOnlyListReverseItor<int>(odds);
	show(rit);

	std::unique_ptr<Itor<int>> uptr_bit = rit.get_base();
	Itor<int> *bit = uptr_bit.get();
	show(bit);

	List<int> odds_copy = odds;
	ReadOnlyListItor<int> it_copy(odds_copy);
	show(it_copy);

	return 0;
}
