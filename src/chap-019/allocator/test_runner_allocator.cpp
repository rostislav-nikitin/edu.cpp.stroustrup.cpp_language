#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <iostream>
#include <algorithm>
#include <iterator>

#include "allocator.hpp"

TEST(AllocatorAllocateTestSuite, Allocate)
{
  Allocator<int> alloc;
  int *ptr = alloc.allocate(10);
  std::fill_n(ptr, 10, 99);
  
  std::copy(ptr, ptr + 10, std::ostream_iterator<int>(std::cout, "\n"));
    
  alloc.deallocate(ptr, 10);
}

struct A
{
  int x;
  int y;

  ~A()
  {
    x = 55;
    y = 77;
  }
};

std::ostream& operator<<(std::ostream &stream, A const &a)
{
  stream << "A{" << a.x << ", " << a.y << "}";

  return stream;
}

TEST(AllocatorConstructDeconstructSuite, ConstructDeconstruct)
{
  Allocator<A> allocator;
  A *ptr = allocator.allocate(10);
  //std::generate_n(ptr, 10, [x = 1, y = 10]() mutable { return A {x++, y--};  });
  std::for_each(ptr, ptr + 10, [x = 1, y = 10, &allocator](A &item_ptr) mutable { allocator.construct(&item_ptr, A{x++, y--}); });
  std::copy(ptr, ptr + 10, std::ostream_iterator<A>(std::cout, "\n"));
  std::for_each(ptr, ptr + 10, [&allocator](A &item_ptr) mutable { allocator.deconstruct(&item_ptr); });
  std::copy(ptr, ptr + 10, std::ostream_iterator<A>(std::cout, "\n"));
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
   
  return RUN_ALL_TESTS();
}
