#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

template<class T>
T U(T const &A, T const &B)
{
	T C;

   	std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::inserter(C, C.begin()));

	return C;
}

template<class T>
T I(T const &A, T const &B)
{
	T C;

   	std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::inserter(C, C.begin()));

	return C;
}

template<class T>
T S(T const &A, T const &B)
{
	T C;

   	std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::inserter(C, C.begin()));

	return C;
}

template<class T>
T SS(T const &A, T const &B)
{
	T C;

   	std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::inserter(C, C.begin()));

	return C;
}

template<class T, template<class> class C>
std::vector<std::pair<T, T>> X(C<T> const &c1, C<T> const &c2)
{
	std::vector<std::pair<T, T>> result;

	for(typename C<T>::iterator i1 = c1.begin(); i1 != c1.end(); ++i1)
		for(typename C<T>::iterator i2 = c2.begin(); i2 != c2.end(); ++i2)
			result.push_back(std::make_pair(*i1, *i2));		

	return result;
}

template<class T>
std::ostream& operator<<(std::ostream& stream, std::pair<T, T> item)
{
	stream << "(" << item.first << ", " << item.second << ")";

	return stream;
}

template<class T, template<class> class C>
void o(C<T> const &c, std::string name)
{
	std::cout << name << " = (";
	std::for_each(c.begin(), c.end(), [i = 0](T const &x) mutable { std::cout << ((i++) ? ", " : "") << x; } );
	std::cout << ")" << std::endl;
}

struct Rec
{
	int x;
	int y;
};

std::ostream& operator<<(std::ostream& stream, Rec const &rec)
{
	stream << "(" <<  rec.x << ", " << rec.y << ")";

	return stream;
}

int main()
{
	std::string big_str = "abcabcdefabcdabccc";
	std::string sub_str = "bc";

	//	Full sequence equals / mismatch
	std::cout << "std::equals(big_str, big_str)=" << std::equal(big_str.begin(), big_str.end(), big_str.begin()) << std::endl;
	std::cout << "std::equals(big_str, reversed big_str)=" << std::equal(big_str.begin(), big_str.end(), big_str.rbegin()) << std::endl;

	std::pair<std::string::iterator, std::string::iterator>	pair_mismatch = std::mismatch(big_str.begin(), big_str.end(), sub_str.begin());
	std::cout << "std::mismatch(big_str, sub_str)::big_str::pos=" << (pair_mismatch.first - big_str.begin()) << "::sub_str::pos=" << (pair_mismatch.second  - sub_str.begin())<< std::endl;

	//	Search family
	std::string::iterator it_search = std::search(big_str.begin(), big_str.end(), sub_str.begin(), sub_str.end());
	std::cout << "std::search::pos=" << (it_search - big_str.begin()) << std::endl;

	std::string::iterator it_search_n = std::search_n (big_str.begin(), big_str.end(), 3, 'c');
	std::cout << "std::search_n::pos=" << (it_search_n - big_str.begin()) << std::endl;

	std::string::iterator it_find_end = std::find_end(big_str.begin(), big_str.end(), sub_str.begin(), sub_str.end());
	std::cout << "std::find_end::pos=" << (it_find_end - big_str.begin()) << std::endl;

	//	Sort
	std::vector<Rec> recs(10);
	std::generate_n(recs.begin(), 10, [i = 0]()mutable{ return Rec{i, 100 - i++}; });
	std::sort(recs.begin(), recs.end(), [](Rec const &lh, Rec const &rh) { return lh.y < rh.y; });
	o(recs, "std::sort(Rec::y)");

	// Partial Sort
	std::partial_sort(recs.begin(), recs.begin() + 4, recs.end(), [](Rec const &lh, Rec const &rh) { return lh.x < rh.x; });
	o(recs, "std::partial_sort(Rec::x)");

	//	Partition
	std::vector<Rec>::iterator it_partition = std::partition(recs.begin(), recs.end(), [](Rec const &rec){ return rec.x % 2; });
	std::cout << "std::partition(Rec::x) = (";
	std::for_each(recs.begin(), it_partition, [i = 0](Rec const &rec) mutable { std::cout << ((i++) ? ", " : "") << rec; } );
	std::cout << ")" << std::endl;

	//	Set
	std::set<int> A {0, 2, 4, 6, 8};
	std::set<int> B {1, 2, 3, 5};
	o(A, "A"); 
	o(B, "B");

	std::set<int> C = U(A, B);
	o(C, "C = A U B");

	std::set<int> D = I(A, B);
	o(D, "D = A /\\ B");

	std::set<int> E = S(A, B);
	o(E, "E = A / B");

	std::set<int> F = SS(A, B);
	o(F, "F = (A / B) U (B / A)");

	std::vector<std::pair<int, int>> G = X(A, B);
	o(G, "G = A X B");
	
	return EXIT_SUCCESS;
}
