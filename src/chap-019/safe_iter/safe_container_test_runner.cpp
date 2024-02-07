#include <string>
#include <vector>
#include <algorithm>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "safe_container.hpp"

class DifferentSizeVectorsFixture : public ::testing::TestWithParam<std::vector<int>>
{
};

TEST_P(DifferentSizeVectorsFixture, TestSuiteSizeAreEquals)
{
  std::vector<int> vec = GetParam();
  
  SafeContainer<std::vector<int>> sut(vec);

  typename std::vector<int>::size_type expected_size = vec.size();

  ASSERT_EQ(expected_size, sut.size());
}

INSTANTIATE_TEST_CASE_P
(
 TestSuiteSizeAreEquals,
 DifferentSizeVectorsFixture,
 ::testing::Values(std::vector<int>(0), std::vector<int>({5}), std::vector<int>({2, 4, 8}))
);

TEST_P(DifferentSizeVectorsFixture, TestSuiteMaxSizeAreEquals)
{
  std::vector<int> vec = GetParam();
  
  SafeContainer<std::vector<int>> sut(vec);

  typename std::vector<int>::size_type expected_max_size = vec.max_size();

  ASSERT_EQ(expected_max_size, sut.max_size());
}

INSTANTIATE_TEST_CASE_P
(
 TestSuiteMaxSizeAreEquals,
 DifferentSizeVectorsFixture,
 ::testing::Values(std::vector<int>(0), std::vector<int>({5}), std::vector<int>({2, 4, 8}))
);


TEST_P(DifferentSizeVectorsFixture, TestSuiteCapacityAreEquals)
{
  std::vector<int> vec = GetParam();
  
  SafeContainer<std::vector<int>> sut(vec);

  typename std::vector<int>::size_type expected_capacity = vec.size();

  ASSERT_EQ(expected_capacity, sut.capacity());
}

INSTANTIATE_TEST_CASE_P
(
 TestSuiteCapacityAreEquals,
 DifferentSizeVectorsFixture,
 ::testing::Values(std::vector<int>(0), std::vector<int>({5}), std::vector<int>({2, 4, 8}))
);

TEST(TestSuit, WhenNothingThenOK)
{
  ASSERT_TRUE(true);
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
