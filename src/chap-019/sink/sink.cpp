#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

template<class C>
class Sink : public std::iterator<std::output_iterator_tag, typename C::value_type>
{
  
public:
  Sink();

  Sink &operator=(const typename C::value_type value);
  void operator++();
  void operator++(int);
  Sink &operator*();
};

template<class C>
Sink<C>::Sink()
{ 
}

template<class C>
Sink<C> &Sink<C>::operator=(const typename C::value_type value)
{
  std::cout << value << std::endl;

  return *this;
}

template<class C>
void Sink<C>::operator++()
{
}

template<class C>
void Sink<C>::operator++(int)
{
}

template<class C>
Sink<C> &Sink<C>::operator*()
{
  return *this;
}

int main()
{
  std::cout << "COUT" << std::endl;
  std::vector<int> ints(10);
  std::generate_n(ints.begin(), 10, [i = 0] () mutable { return i++; });
  //  std::for_each(sink_int_itor,

    
  Sink<std::vector<int>> sink_int_itor;

  std::copy(ints.begin(), ints.end(), sink_int_itor);
  
  
  
  return EXIT_SUCCESS;
}
