#include <stdexcept>
#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>

#include "safe_iterator.hpp"
#include "safe_container.hpp"


// Experiment with template recursion
template<class TI, template<class> class TO>
class A
{
  TI value;
public:
  A() : value()
  {
  }
};

int main()
{
  std::cout << "START EXECUTION" << std::endl;
  
  std::vector<int> nums(10);
  std::generate_n(nums.begin(), 10, [i = 1]() mutable { return i++; });
  SafeIterator<std::vector<int>> it_vec_begin(nums);
  SafeIterator<std::vector<int>> it_vec_end(nums, true);


  std::copy(it_vec_begin, it_vec_end, std::ostream_iterator<int>(std::cout));

  std::cout << std::endl << "Another numbers" << std::endl;

  try
  {
    it_vec_end++;
  }
  catch(std::out_of_range &ex)
  {
    std::cout << ex.what() << std::endl;
  }


  std::cout << std::endl << "Another numbers" << std::endl;
  std::vector<int> another_nums(5);
  std::generate_n(another_nums.begin(), 5, [i = 10] () mutable { return --i; });
  SafeIterator<std::vector<int>> it_another(another_nums);
  SafeIterator<std::vector<int>> it_another_end(another_nums, true);
  std::copy(it_another, it_another_end, std::ostream_iterator<int>(std::cout));

  std::copy(nums.begin(), nums.end(), std::back_inserter(another_nums));
  
  try
    {
      std::copy(it_another, it_another_end, std::ostream_iterator<int>(std::cout));
    }
  catch(std::runtime_error &ex)
    {
      std::cout << std::endl << ex.what() << std::endl;
    }
  

  SafeContainer<std::vector<int>> container(nums);
  int num = 100;
  container.push_back(num);
  container.push_back(200);

  std::cout << "SafeContainer output" << std::endl;
  std::copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout));

  std::cout << std::endl << "END EXECUTION" << std::endl;
  
  return EXIT_SUCCESS;
}
