#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "pool.hpp"
#include "allocator.hpp"
#include "vector.hpp"

TEST(TestSuite, WhenOkThenOk)
{
	Allocator<int> allocator;
	Pool &pool = allocator.get_pool();
	Vector<int> sut(0, 0, allocator);

	ASSERT_EQ(0, sut.size());
	ASSERT_EQ(8, sut.capacity());
	Pool::PoolStat stat = pool.get_stat();
	ASSERT_EQ(1, stat.allocated);

	std::cout << std::string(stat) << std::endl;

	int expected = 11;
	sut.push_back(expected);
	ASSERT_EQ(1, sut.size());
	ASSERT_EQ(8, sut.capacity());
	int actual = sut.back();
	ASSERT_EQ(expected, actual);

	sut.pop_back();
	ASSERT_EQ(0, sut.size());
	ASSERT_EQ(8, sut.capacity());

}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
