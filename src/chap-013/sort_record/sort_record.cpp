#include <iostream>
#include <vector>

struct Record
{
	float price;
	int count;
};

template<class T>
class PriceComparer
{
public:
	static bool less(T const &lhs, T const &rhs);
};


template<class T>
bool PriceComparer<T>::less(T const &lhs, T const &rhs)
{
	return lhs.price < rhs.price;
}

template<class T>
class CountComparer
{
public:
	static bool less(T const &lhs, T const &rhs);
};

template<class T>
bool CountComparer<T>::less(T const &lhs, T const &rhs)
{
	return lhs.count < rhs.count;
}

template<class T, class U = PriceComparer<Record>>
void sort(std::vector<T> &elements)
{
	while(true)
	{
		bool changed = false;

		for(typename std::vector<T>::iterator it = elements.begin(); (it + 1) != elements.end(); ++it)
		{
			if(U::less(*(it + 1), *it))
			{
				std::iter_swap(it, it + 1);
				changed = true;
				break;
			}
		}	

		if(!changed)
			break;
	}
}

void print_recs(std::vector<Record> elements)
{
	for(std::vector<Record>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		std::cout << "Price=" << it->price << "\t Count=" << it->count << std::endl;
	}
}


int main()
{
	std::vector<Record> recs({Record{10.f, 50}, Record{25.5f, 4}, Record{3.25f, 16}});

	std::cout << std::endl;
	std::cout << "Unsorted" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	print_recs(recs);
	sort(recs);
	std::cout << std::endl;
	std::cout << "Sorted by price" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	print_recs(recs);
	sort<Record, CountComparer<Record>>(recs);
	std::cout << std::endl;
	std::cout << "Sorted by count" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	print_recs(recs);

	return 0;
}

