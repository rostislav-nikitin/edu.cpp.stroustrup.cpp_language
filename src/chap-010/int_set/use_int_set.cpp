#include "use_int_set.h"

int main()
{
	using Set::Int_set;

	std::cout << "USE INT SET" << std::endl;

	Int_set empty_set;
	std::cout << "empty_set empty: " << empty_set.empty() << std::endl;
	empty_set.print();

	Int_set set_one {5, 0, 2, 4, 6, 8}; 
	std::cout << "set_one size: " << set_one.size() << std::endl;
	set_one.print();

	Int_set set_two {6, 0, 1, 3, 5, 7, 9}; 
	std::cout << "set_two size: " << set_two.size() << std::endl;
	set_two.print();

	Int_set union_set = set_one.uni(set_two);
	std::cout << "union_set size: " << union_set.size() << std::endl;
	union_set.print();

	Int_set intersect_set = set_one.intersect(set_two);
	std::cout << "intersect_set size: " << intersect_set.size() << std::endl;
	intersect_set.print();

	Int_set substract_set = set_one.substract(set_two);
	std::cout << "substract_set size: " << substract_set.size() << std::endl;
	substract_set.print();

	return 0;
}
