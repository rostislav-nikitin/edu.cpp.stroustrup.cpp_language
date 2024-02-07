#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <stdexcept>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>

#include "pool.hpp"

TEST(TestSuitePoolGetBucketSize, WhenSizeIsZeroThenReturnsSizeOfILink)
{
  Pool sut;
  // 2 * sizeof(void *) - size of ILink (it contains ILink *previous, ILink *next)
  size_t expected = 2 * sizeof(void *);
  size_t actual = sut.get_bucket_size(0);

  ASSERT_EQ(expected, actual);   
}

size_t get_nearest_size_pow_of_two(size_t number)
{
  int result = 1;
  
  while(result < number)
    result <<= 1;

  return result;
}

TEST(TestSuitePoolGetBucketSize, WhenSizeIsMoreThenILinkThenReturnsNearestTo2PowerN)
{
  Pool sut;

  for(size_t size = 0; size <= pow(2, 20); ++size)
  {
    // 2 * sizeof(void *) - size of ILink (it contains ILink *previous, ILink *next)
    size_t min_size = (2 * sizeof(void *)) +  size;
    size_t expected = get_nearest_size_pow_of_two(min_size);

    size_t actual = sut.get_bucket_size(size);

    ASSERT_EQ(expected, actual);
  }
}

TEST(TestSuitePoolGetHash, WhenSizeIsZeroThenMinusOne)
{
  Pool sut;
  
  int expected = -1;
  int actual = sut.get_hash(0);

  ASSERT_EQ(expected, actual);
}

TEST(TestSuitePoolGetHash, WhenSizeMoreThanZeroThenLogWithBaseTwo)
{
  Pool sut;

  for(int power = 0; power <= 20; ++power)
  {
    size_t num = pow(2, power);
    
    int expected = power;
    int actual = sut.get_hash(num);

    ASSERT_EQ(expected, actual);
  }
}

TEST(TestSuitePoolGetBucketIndex, WhenSizeIsZeroThenNoThrow)
{
  Pool sut;
  
  size_t size = 0;
  ASSERT_NO_THROW(sut.get_bucket_index(size));
}

int log2(size_t num)
{
  int result = -1;
  
  while(num)
  {
    result++;
    num >>= 1;
  }

  return result;
}

TEST(TestSuitePoolGetBucketIndex, WhenSizeIsInRangeThenLog2)
{
  Pool sut;
  
  for(int power = 0; power <= 19; ++power)
  {
    size_t data_size = pow(2, power);
    size_t full_size = data_size + sizeof(void *) * 2;
    int expected = log2(get_nearest_size_pow_of_two(full_size));
    
    //log2(get_nearest_size_pow_of_two(2 * sizeof(void *)));
    int actual = sut.get_bucket_index(pow(2, power));

    ASSERT_EQ(expected, actual);
  }
}

TEST(TestSuitePoolGetBucketIndex, WhenSizeIsOutOfRangeThenThrow)
{
  Pool sut;
  
  ASSERT_THROW(sut.get_bucket_index(pow(2, Pool::BUCKETS_SIZE)), std::out_of_range);
}

class PoolAllocateDeallocateFixture : public ::testing::TestWithParam<std::tuple<int, int>>
{
};

TEST_P(PoolAllocateDeallocateFixture, AllocateDeallocate)
{
  std::tuple<int, int> param = GetParam();

  //  std::cout << std::get<0>(param) << "::" << std::get<1>(param) << std::endl;

  size_t ELEMENT_SIZE_POWER = std::get<0>(param);
  size_t ELEMENT_SIZE = pow(2, ELEMENT_SIZE_POWER);
  size_t ELEMENTS = std::get<1>(param);

  Pool sut;
  
  std::vector<void *>ptrs;

  //Fill ptrs with allocated items
  for(int idx = 0; idx < ELEMENTS; ++idx)
  {
    void *ptr = sut.allocate(ELEMENT_SIZE);
    char *c = static_cast<char *>(ptr);
    std::fill_n(c, ELEMENT_SIZE, 'B');
    //    *c = 'A';
    ptrs.push_back(ptr);
  }

  // Deallocate items with backward ordred (chunks should back into the pool buckets)
  for(int idx = ELEMENTS - 1; idx >= 0; --idx)
  {
    sut.deallocate(ptrs[idx], ELEMENT_SIZE);
  }

  // Allocate items again (chunks shoul be reused istread of new created)
  for(int idx = 0; idx < ELEMENTS; ++idx)
  {
    void *ptr = sut.allocate(ELEMENT_SIZE);
    ASSERT_EQ(ptrs[idx], ptr);
  }

  // Free memory
  for(int idx = 0; idx < ELEMENTS; ++idx)
  {
    sut.deallocate(ptrs[idx], ELEMENT_SIZE);
  }
}

INSTANTIATE_TEST_SUITE_P(AllocateDeallocate, PoolAllocateDeallocateFixture,
			 ::testing::Combine(::testing::Range(0, 20, 1), ::testing::Range(1, 110, 10)));

TEST(TestSuitePoolAllocateNew, WhenThen)
{
  //int x;
  //  std::cin >> x;
  Pool sut;

  int expected = 100;

  //const size_t ELEMENT_SIZE = sizeof(char) * 10;//sizeof(int);
  const size_t ELEMENTS = 10;

  for(size_t power = 0; power < 20; ++power)
  {
    size_t ELEMENT_SIZE = pow(2, power);
  
    std::vector<void *>ptrs;

    for(int idx = 0; idx < ELEMENTS; ++idx)
      {
	void *ptr = sut.allocate(ELEMENT_SIZE);
	char *c = static_cast<char *>(ptr);
	std::fill_n(c, ELEMENT_SIZE, 'B');
	//    *c = 'A';
	ptrs.push_back(ptr);
      }

  
    //std::cin >> x;

    for(int idx = ELEMENTS - 1; idx >= 0; --idx)
      {
	sut.deallocate(ptrs[idx], ELEMENT_SIZE);
      }

    //std::cin >> x;

    for(int idx = 0; idx < ELEMENTS; ++idx)
      {
	void *ptr = sut.allocate(ELEMENT_SIZE);
	ASSERT_EQ(ptrs[idx], ptr);
      }

    //std::cin >> x;

    for(int idx = 0; idx < ELEMENTS; ++idx)
      {
	sut.deallocate(ptrs[idx], ELEMENT_SIZE);
      }

    //std::cin >> x;

    /*
      int *x = (int *)sut.allocate(sizeof(int));
  
      *x = expected;

      ASSERT_EQ(expected, *x);

      sut.deallocate(x, sizeof(int));

      int *y = (int* )sut.allocate(sizeof(int));

      *y = expected + 1;

      ASSERT_EQ(expected + 1, *y);
    */
  }
}


TEST(TestSuiteAllocateDeallocate, AllocteDeallocate)
{
  int const ITEMS_COUNT = 20;
  
  std::vector<void *> ptrs;
  Pool sut;

  for(int idx = 0; idx < 10; ++idx)
  {
    void* ptr = sut.allocate(sizeof(int) * ITEMS_COUNT);
    //    std::cout << "Allocated::ptr=" << ptr << std::endl;
    ptrs.push_back(ptr);
  }

  for(int idx = 9; idx >= 0; --idx)
  {
    sut.deallocate(ptrs[idx], sizeof(int) * ITEMS_COUNT);
  }

  for(int idx = 0; idx < 10; ++idx)
  {
    void* ptr = sut.allocate(sizeof(int) * ITEMS_COUNT);    
  }

  for(int idx = 9; idx >= 0; --idx)
  {
    sut.deallocate(ptrs[idx], sizeof(int) * ITEMS_COUNT);
  }  

}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);

  //  int result = RUN_ALL_TESTS();
  //  int x;
  //  std::cin >> x;
  
  return RUN_ALL_TESTS();
}
