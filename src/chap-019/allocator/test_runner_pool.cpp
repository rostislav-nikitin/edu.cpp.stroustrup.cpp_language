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

class PoolMock : public Pool
{
public:
  size_t get_bucket_size(size_t item_size) const;
  int get_hash(size_t size) const;
  int get_bucket_index(size_t required_size) const;
  size_t get_bucket_size_by_index(int bucket_index) const;
};

size_t PoolMock::get_bucket_size(size_t item_size) const
{
  return Pool::get_bucket_size(item_size);
}

int PoolMock::get_hash(size_t size) const
{
 return Pool::get_hash(size);  
}

int PoolMock::get_bucket_index(size_t required_size) const
{
  return Pool::get_bucket_index(required_size);
}
size_t PoolMock::get_bucket_size_by_index(int bucket_index) const
{
  return Pool::get_bucket_size_by_index(bucket_index);
}

size_t get_nearest_size_pow_of_two(size_t number)
{
  int result = 1;
  
  while(result < number)
    result <<= 1;

  return result;
}

TEST(TestSuitePoolGetBucketSize, WhenSizeIsZeroThenReturnsSizeOfILink)
{
  PoolMock sut;
  // 2 * sizeof(void *) - size of ILink (it contains ILink *previous, ILink *next)
  size_t expected = 2 * sizeof(void *);
  size_t actual = sut.get_bucket_size(0);

  ASSERT_EQ(expected, actual);   
}

TEST(TestSuitePoolGetBucketSize, WhenSizeIsMoreThenILinkThenReturnsNearestTo2PowerN)
{
  PoolMock sut;

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
  PoolMock sut;
  
  int expected = -1;
  int actual = sut.get_hash(0);

  ASSERT_EQ(expected, actual);
}

TEST(TestSuitePoolGetHash, WhenSizeMoreThanZeroThenLogWithBaseTwo)
{
  PoolMock sut;

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
  PoolMock sut;
  
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
  PoolMock sut;
  
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
  PoolMock sut;
  
  ASSERT_THROW(sut.get_bucket_index(pow(2, Pool::BUCKETS_SIZE)), std::out_of_range);
}

TEST(TestSuiteGetStat, WhenPoolIsEmptyThenStatIsZeroes)
{
  // Arrage
  Pool pool;
  Pool::PoolStat sut = pool.get_stat();

  // Act / Assert
  ASSERT_EQ(0, sut.allocated);
  ASSERT_EQ(0, sut.used);
  ASSERT_EQ(0, sut.free);

  std::for_each(sut.buckets.begin(), sut.buckets.end(), [](Pool::BucketStat const &bs)
  {
    ASSERT_EQ(0, bs.allocated);
  });
}

TEST(TestSuiteGetStat, WhenPoolIsOnePerBucketStatThenStatSuccess)
{
  // Arrage
  std::vector<void *> ptrs;
  Pool pool;

  size_t used = 0;
  size_t free = 0;

  for(int power = 0; power < 20; ++power)
  {
    size_t size_to_alloc = pow(2, power);
    ++used;
    void * ptr = pool.allocate(size_to_alloc);
    ptrs.push_back(ptr);
  }

  // Act
  Pool::PoolStat sut = pool.get_stat();

  // Assert
  ASSERT_EQ(20, sut.allocated);
  ASSERT_EQ(used, sut.used);
  ASSERT_EQ(free, sut.free);

  std::for_each(sut.buckets.begin(), sut.buckets.end(), [](Pool::BucketStat const &bs)
  {
    if(bs.size < (1 + 2 * (sizeof(void *))))
    {
      ASSERT_EQ(0, bs.allocated);
      ASSERT_EQ(0, bs.used);
      ASSERT_EQ(0, bs.free);
    }
    else if(bs.size == 32)
    {
      ASSERT_EQ(5, bs.allocated);
      ASSERT_EQ(5, bs.used);
      ASSERT_EQ(0, bs.free);
    }
    else
    {
      ASSERT_EQ(1, bs.allocated);
      ASSERT_EQ(1, bs.used);
      ASSERT_EQ(0, bs.free);
    }
  });

  // Dealloc
  for(int power = 0; power < 20; ++power)
  {
    size_t size_to_dealloc = pow(2, power);
    size_t actual_size = (size_to_dealloc + 2 * sizeof(void*));
    --used;
    ++free;
    void *ptr = ptrs[power];
    pool.deallocate(ptr, size_to_dealloc);
  }
  
  sut = pool.get_stat();

  ASSERT_EQ(20, sut.allocated);
  ASSERT_EQ(used, sut.used);
  ASSERT_EQ(free, sut.free);

  std::for_each(sut.buckets.begin(), sut.buckets.end(), [](Pool::BucketStat const &bs)
  {
    if(bs.size < (1 + 2 * (sizeof(void *))))
    {
      ASSERT_EQ(0, bs.allocated);
      ASSERT_EQ(0, bs.used);
      ASSERT_EQ(0, bs.free);
    }
    else if(bs.size == 32)
    {
      ASSERT_EQ(5, bs.allocated);
      ASSERT_EQ(0, bs.used);
      ASSERT_EQ(5, bs.free);
    }
    else
    {
      ASSERT_EQ(1, bs.allocated);
      ASSERT_EQ(0, bs.used);
      ASSERT_EQ(1, bs.free);
    }
  });

}

class PoolAllocateDeallocateFixture : public ::testing::TestWithParam<std::tuple<int, int>>
{
};

TEST_P(PoolAllocateDeallocateFixture, AllocateDeallocate)
{
  // Arrage
  std::tuple<int, int> param = GetParam();

  //  std::cout << std::get<0>(param) << "::" << std::get<1>(param) << std::endl;

  size_t ELEMENT_SIZE_POWER = std::get<0>(param);
  size_t ELEMENT_SIZE = pow(2, ELEMENT_SIZE_POWER);
  size_t ELEMENTS = std::get<1>(param);

  //std::cout << "ELEMENT_SIZE=" << ELEMENT_SIZE << "ELEMENTS=" << ELEMENTS << std::endl;

  Pool sut;
  Pool::PoolStat stat;
  stat = sut.get_stat();

  ASSERT_EQ(0, stat.allocated);
  ASSERT_EQ(0, stat.used);
  ASSERT_EQ(0, stat.free);
 
  std::vector<void *>ptrs;

  // Act / Assert
  //Fill ptrs with allocated items
  //std::cout << "A1" << std::endl;
  for(int idx = 0; idx < ELEMENTS; ++idx)
  {
    void *ptr = sut.allocate(ELEMENT_SIZE);
    char *c = static_cast<char *>(ptr);
    std::fill_n(c, ELEMENT_SIZE, 'X');
    //*c = 'A';
    ptrs.push_back(ptr);
  }
  
  stat = sut.get_stat();
  ASSERT_EQ(ELEMENTS, stat.allocated);
  ASSERT_EQ(ELEMENTS, stat.used);
  ASSERT_EQ(0, stat.free);

  
  //std::cout << "D1" << std::endl;
  // Deallocate items with backward ordred (chunks should back into the pool buckets)
  for(int idx = ELEMENTS - 1; idx >= 0; --idx)
  {
    sut.deallocate(ptrs[idx], ELEMENT_SIZE);
  }
  
  stat = sut.get_stat();
  ASSERT_EQ(ELEMENTS, stat.allocated);
  ASSERT_EQ(0, stat.used);
  ASSERT_EQ(ELEMENTS, stat.free);

  //std::cout << "A2" << std::endl;
  // Allocate items again (chunks shoul be reused istread of new created)
  for(int idx = 0; idx < ELEMENTS; ++idx)
  {
    void *ptr = sut.allocate(ELEMENT_SIZE);
    ASSERT_EQ(ptrs[idx], ptr);
  }

  stat = sut.get_stat();
  ASSERT_EQ(ELEMENTS, stat.allocated);
  ASSERT_EQ(ELEMENTS, stat.used);
  ASSERT_EQ(0, stat.free);

  
  //  std::cout << "D2::" << ELEMENTS << "::" << ELEMENT_SIZE << std::endl;
  // Free memory
  for(int idx = 0; idx < ELEMENTS; ++idx)
  {
    sut.deallocate(ptrs[idx], ELEMENT_SIZE);
  }
  
  stat = sut.get_stat();
  ASSERT_EQ(ELEMENTS, stat.allocated);
  ASSERT_EQ(0, stat.used);
  ASSERT_EQ(ELEMENTS, stat.free);
  //  std::cout << (std::string)sut.get_stat() << std::endl;

}

INSTANTIATE_TEST_SUITE_P(AllocateDeallocate, PoolAllocateDeallocateFixture,
			 ::testing::Combine(::testing::Range(0, 20, 1), ::testing::Range(1, 110, 10)));

/*
TEST(TestSuiteAllocateDeallocate, AllocteDeallocate)
{
  int const ITEMS_COUNT = 1;
  
  std::vector<void *> ptrs;
  Pool sut;

  for(int idx = 0; idx < 11; ++idx)
  {
    void *ptr = sut.allocate(1 * ITEMS_COUNT);
    char *c = static_cast<char *>(ptr);
    //    std::cout << "Allocated::ptr=" << ptr << std::endl;
    std::fill_n(c, 1, 'X');
    ptrs.push_back(ptr);
  }

  std::cout << "DSFSDF" << std::endl;
  std::cout << (std::string)sut.get_stat() << std::endl;

  for(int idx = 10; idx >= 0; --idx)
  {
    sut.deallocate(ptrs[idx], 1 * ITEMS_COUNT);
  }

  std::cout << (std::string)sut.get_stat() << std::endl;
    
  for(int idx = 0; idx < 11; ++idx)
  {
    void* ptr = sut.allocate(1 * ITEMS_COUNT);    
  }
  
  std::cout << (std::string)sut.get_stat() << std::endl;

  for(int idx = 10; idx >= 0; --idx)
  {
    sut.deallocate(ptrs[idx], 1 * ITEMS_COUNT);
  }

  std::cout << (std::string)sut.get_stat() << std::endl;

}
*/
int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);

  //  int result = RUN_ALL_TESTS();
  //  int x;
  //  std::cin >> x;
  
  return RUN_ALL_TESTS();
}
