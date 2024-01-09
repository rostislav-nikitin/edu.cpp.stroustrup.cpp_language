#include <stdexcept>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "vector_abstractions.hpp"

//VectorItor tests
TEST(VectorItorFirstTestSuite, WhenVectorIsEmptyThenFirstIsNullPtr)
{
	//Arrage
	Containers::Vector<int> vec;
	Containers::VectorItor<int, Containers::VectorStorageByValue<int>> sut(vec);
	//Act
	//Assert
	ASSERT_EQ(nullptr, sut.first());
}

TEST(VectorItorFirstTestSuite, WhenVectorIsNotEmptyThenFirstIsNotNullPtr)
{
	//Arrage
	Containers::Vector<int> vec;
	vec.push_back(12);
	Containers::VectorItor<int, Containers::VectorStorageByValue<int>> sut(vec);
	//Act
	//Assert
	ASSERT_NE(nullptr, sut.first());
}

TEST(VectorItorNextTestSuite, WhenVectorIsNotEmptyThenNextIsNotNullPtr)
{
	//Arrage
	Containers::Vector<int> vec;
	vec.push_back(11);
	Containers::VectorItor<int, Containers::VectorStorageByValue<int>> sut(vec);
	//Act
	//Assert
	ASSERT_NE(nullptr, sut.next());
}

TEST(VectorItorNextTestSuite, WhenVectorMoreThenOneElementAndFirstIsCalledThenNextIsNotNullPtr)
{
	//Arrage
	Containers::Vector<int> vec;
	vec.push_back(12);
	vec.push_back(56);
	Containers::VectorItor<int, Containers::VectorStorageByValue<int>> sut(vec);
	//Act
	sut.first();
	//Assert
	ASSERT_NE(nullptr, sut.next());
}

TEST(VectorItorNextTestSuite, WhenLastElementReachedThenNextIsNullPtr)
{
	//Arrage
	Containers::Vector<int> vec;
	vec.push_back(12);
	vec.push_back(56);
	Containers::VectorItor<int, Containers::VectorStorageByValue<int>> sut(vec);
	sut.first();
	//Act
	sut.next();
	sut.next();
	//Assert
	ASSERT_EQ(nullptr, sut.next());
}

TEST(VectorItorNextTestSuite, WhenVectorNotEmptyThenAllElementsReachedInRightOrder)
{
	//Arrage
	int actual[4] {1, 5, 22, 98};
	Containers::Vector<int> vec;
	std::for_each(&actual[0], &actual[0] + sizeof(actual)/sizeof(int), [&vec] (int &value)  { vec.push_back(value); });
	Containers::VectorItor<int, Containers::VectorStorageByValue<int>> sut(vec);
	//Act
	//Assert
	int idx = 0;
	for(int *it = sut.first(); it != nullptr; it = sut.next(), ++idx)
	{
		ASSERT_EQ(actual[idx], *it);
	}
}

TEST(VectorItorReadWriteTestSuite, WhenIteratingAndElementInsertedThenContinueIterating)
{
	
	int actual[4] {1, 5, 22, 98};
	Containers::Vector<int> vec;
	std::for_each(&actual[0], &actual[0] + sizeof(actual)/sizeof(int), [&vec] (int &value)  { vec.push_back(value); });
	Containers::VectorItor<int, Containers::VectorStorageByValue<int>> sut(vec);
	size_t idx = 0;
	for(typename Containers::VectorItor<int>::iterator it = sut.first(); it != nullptr; it = sut.next(), ++idx)
	{
		if(idx == 0)
			vec.insert_before(0, 0);
		if(idx == 1)
			vec.remove(1);
		if(idx == 2)
			vec.insert_before(3, 10);
		if(idx == 3)
			vec.insert_before(4, 90);

		ASSERT_EQ(actual[idx], *it);
	}
	Containers::VectorItor<int> updated(vec);

	for(typename Containers::VectorItor<int>::iterator it = updated.first(); it != nullptr; it = updated.next(), ++idx)
	{
		std::cout << *it << std::endl;
	}
}

//VectorReverseItor
TEST(VectorReverseItorFirstTestSuite, WhenVectorIsEmptyThenFirstIsNullptr)
{
	//Arrage
	Containers::Vector<int> vec;
	Containers::VectorItor<int, Containers::VectorStorageByValue<int>> sut(vec);
	//Act
	//Assert
	ASSERT_EQ(nullptr, sut.first());
}

TEST(VectorReverseItorFirstTestSuite, WhenVectorIsNotEmptyThenFirstIsNotNullptr)
{
	//Arrage
	Containers::Vector<int> vec;
	vec.push_back(11);
	Containers::VectorItor<int, Containers::VectorStorageByValue<int>> sut(vec);
	//Act
	//Assert
	ASSERT_NE(nullptr, sut.first());
}

TEST(VectorReverseItorFirstTestSuite, WhenVectorIsOneElementThenFirstIsFirstElement)
{
	//Arrage
	int x = 55;
	Containers::Vector<int> vec;
	vec.push_back(x);
	Containers::VectorItor<int, Containers::VectorStorageByValue<int>> sut(vec);
	//Act
	//Assert
	ASSERT_EQ(x, *sut.first());
}

TEST(VectorReverseItorFirstTestSuite, WhenVectorIsSomeElementsThenFirstIsLastElement)
{
	//Arrage
	int actual[] = {4, 55, 23, 454};
	Containers::Vector<int> vec;
	std::for_each(&actual[0], &actual[0] + sizeof(actual)/sizeof(int), [&vec](int &value) { vec.push_back(value); });
	Containers::VectorReverseItor sut(vec);
	//Act
	//Assert
	ASSERT_EQ(actual[sizeof(actual)/sizeof(int) - 1], *sut.first());
}

TEST(VectorReverseItorNextTestSuite, WhenVectorIsEmptyThenNextIsNullptr)
{
	//Arrage
	Containers::Vector<int> vec;
	Containers::VectorReverseItor sut(vec);
	//Act
	//Assert
	ASSERT_EQ(nullptr, sut.next());
}

TEST(VectorReverseItorNextTestSuite, WhenVectorIsOneElementThenNextAfterFirstIsNullptr)
{
	//Arrage
	Containers::Vector<int> vec;
	vec.push_back(11);
	Containers::VectorReverseItor sut(vec);
	//Act
	sut.first();
	//Assert
	ASSERT_EQ(nullptr, sut.next());
}

TEST(VectorReverseItorNextTestSuite, WhenVectorIsMoreThenOneElementThenNextAfterFirstIsNotNullptr)
{
	//Arrage
	Containers::Vector<int> vec;
	vec.push_back(15);
	vec.push_back(45);
	Containers::VectorReverseItor sut(vec);
	//Act
	sut.first();
	//Assert
	ASSERT_NE(nullptr, sut.next());
}

TEST(VectorReverseItorSequenceTestSuite, WhenVectorIsNotEmptyThenIteratesInReverseOrder)
{
	//Arrage
	int actual[] = {4, 55, 23, 454};
	Containers::Vector<int> vec;
	std::for_each(&actual[0], &actual[0] + sizeof(actual)/sizeof(int), [&vec](int &value) { vec.push_back(value); });
	Containers::VectorReverseItor sut(vec);
	//Act
	//Assert
	int idx = 0;
	for(int *it = sut.first(); it != nullptr; it = sut.next(), ++idx)
	{
		ASSERT_EQ(actual[sizeof(actual) / sizeof(int) - idx - 1], *it);
	}
}

TEST(VectorReverseItorBaseTestSuite, WhenVectorIsEmptyThenBaseIsEmpty)
{
	//Arrage
	Containers::Vector<int> vec;
	Containers::VectorReverseItor rit(vec);
	//Act
	std::unique_ptr<Containers::Itor<int>> sut = rit.get_base();
	//Assert
	ASSERT_EQ(nullptr, sut->first());
	ASSERT_EQ(nullptr, sut->next());
}

TEST(VectorReverseItorBaseSequenceTestSuite, WhenVectorIsNotEmptyThenBaseIteratesInForwardOrder)
{
	//Arrage
	int actual[] = {4, 55, 23, 454};
	Containers::Vector<int> vec;
	std::for_each(&actual[0], &actual[0] + sizeof(actual)/sizeof(int), [&vec](int &value) { vec.push_back(value); });
	Containers::VectorReverseItor rit(vec);
	std::unique_ptr<Containers::Itor<int>> sut = rit.get_base();
	//Act
	//Assert
	int idx = 0;
	for(int *it = sut->first(); it != nullptr; it = sut->next(), ++idx)
	{
		ASSERT_EQ(actual[idx], *it);
	}
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
