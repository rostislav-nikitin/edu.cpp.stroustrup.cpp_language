#include <stdexcept>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "vector_abstractions.hpp"

//Vector::ctor[copy]
TEST(VectorCopyCtorTestSuite, WhenCopyCtorCalledThenItemsCopied)
{
	//Arrage
	Containers::Vector<int> vec;
	vec.push_back(10);
	vec.push_back(30);
	vec.push_back(20);
	//Act
	Containers::Vector<int> sut(vec);
	vec.insert_before(0, 5);
	//Assert
	ASSERT_NE(vec[0], sut[0]);
	ASSERT_EQ(5, vec[0]);
	ASSERT_EQ(10, sut[0]);
	ASSERT_EQ(4, vec.get_size());
	ASSERT_EQ(3, sut.get_size());
}
TEST(VectorCopyCtorTestSuite, WhenCopyCtorCalledThenSameItemsCopied)
{
	//Arrage
	int actual[3] = {4, 5008, 190};
	Containers::Vector<int> vec;
	std::for_each(&actual[0], &actual[0] + sizeof(actual)/sizeof(int), [&vec](int &value) { vec.push_back(value); });
	//Action
	Containers::Vector<int> sut(vec);
	//Assert
	for(int idx = 0; idx < sizeof(actual)/sizeof(int); ++idx)
	{
		ASSERT_EQ(vec[idx], sut[idx]);
	}
}
//Vector::ctor[move]
TEST(VectorMoveCtorTestSuite, WhenMoveCtorCalledThenItemsMoved)
{
	//Arrage
	Containers::Vector<int> vec;
	vec.push_back(10);
	vec.push_back(30);
	vec.push_back(20);
	//Act
	Containers::Vector<int> sut(std::move(vec));
	//Assert
	ASSERT_EQ(0, vec.get_size());
	ASSERT_EQ(0, vec.get_capacity());
	ASSERT_EQ(3, sut.get_size());
}
TEST(VectorMoveCtorTestSuite, WhenMoveCtorCalledThenSameItemsCopied)
{
	//Arrage
	int actual[3] = {4, 5008, 190};
	Containers::Vector<int> vec;
	std::for_each(&actual[0], &actual[0] + sizeof(actual)/sizeof(int), [&vec](int &value) { vec.push_back(value); });
	//Action
	Containers::Vector<int> sut(std::move(vec));
	//Assert
	for(int idx = 0; idx < sizeof(actual)/sizeof(int); ++idx)
	{
		ASSERT_EQ(actual[idx], sut[idx]);
	}
}
//Vector::operator=[copy]
TEST(VectorCopyAssignTestSuite, WhenCopyAssignCalledThenItemsCopied)
{
	//Arrage
	Containers::Vector<int> vec;
	vec.push_back(10);
	vec.push_back(30);
	vec.push_back(20);
	//Act
	Containers::Vector<int> sut;
	sut = vec;
	vec.insert_before(0, 5);
	//Assert
	ASSERT_NE(vec[0], sut[0]);
	ASSERT_EQ(5, vec[0]);
	ASSERT_EQ(10, sut[0]);
	ASSERT_EQ(4, vec.get_size());
	ASSERT_EQ(3, sut.get_size());
}
TEST(VectorCopyAssignTestSuite, WhenCopyAssignCalledThenSameItemsCopied)
{
	//Arrage
	int actual[3] = {4, 5008, 190};
	Containers::Vector<int> vec;
	std::for_each(&actual[0], &actual[0] + sizeof(actual)/sizeof(int), [&vec](int &value) { vec.push_back(value); });
	//Action
	Containers::Vector<int> sut;
	sut = vec;
	//Assert
	for(int idx = 0; idx < sizeof(actual)/sizeof(int); ++idx)
	{
		ASSERT_EQ(vec[idx], sut[idx]);
	}
}
//Vector::operator=[move]
TEST(VectorMoveAssignTestSuite, WhenMoveAssignCalledThenItemsMoved)
{
	//Arrage
	Containers::Vector<int> vec;
	vec.push_back(10);
	vec.push_back(30);
	vec.push_back(20);
	//Act
	Containers::Vector<int> sut;
	sut = std::move(vec);
	//Assert
	ASSERT_EQ(0, vec.get_size());
	ASSERT_EQ(0, vec.get_capacity());
	ASSERT_EQ(3, sut.get_size());
}
TEST(VectorMoveAssignTestSuite, WhenMoveAssignCalledThenSameItemsCopied)
{
	//Arrage
	int actual[3] = {4, 5008, 190};
	Containers::Vector<int> vec;
	std::for_each(&actual[0], &actual[0] + sizeof(actual)/sizeof(int), [&vec](int &value) { vec.push_back(value); });
	//Action
	Containers::Vector<int> sut;
	sut = std::move(vec);
	//Assert
	for(int idx = 0; idx < sizeof(actual)/sizeof(int); ++idx)
	{
		ASSERT_EQ(actual[idx], sut[idx]);
	}
}
//Vector::reserve
TEST(VectorReserveTestSuite, WhenReservedLessThanSizeThenThrow)
{
	//Arrage
	Containers::Vector<int> sut;
	sut.push_back(5);
	sut.push_back(15);
	//Act
	//Assert
	ASSERT_THROW(sut.reserve(1), std::out_of_range);
}
TEST(VectorReserveTestSuite, WhenReservedEmptyThanCapacityChanged)
{
	//Arrage
	Containers::Vector<int> sut(8);
	//Act
	sut.reserve(256);
	//Assert
	ASSERT_EQ(256, sut.get_capacity());
}
TEST(VectorReserveTestSuite, WhenReservedLessNotEmptyThanItemsStayTheSameButCapacityChanged)
{
	//Arrage
	int actual[3] = {4, 5008, 190};
	Containers::Vector<int> sut(8);
	std::for_each(&actual[0], &actual[0] + sizeof(actual)/sizeof(int), [&sut](int &value) { sut.push_back(value); });
	//Action
	sut.reserve(3);
	//Assert
	for(int idx = 0; idx < sizeof(actual)/sizeof(int); ++idx)
	{
		ASSERT_EQ(actual[idx], sut[idx]);
	}
	ASSERT_EQ(3, sut.get_capacity());
}
TEST(VectorReserveTestSuite, WhenReservedMoreNotEmptyThanItemsStayTheSameButCapacityChanged)
{
	//Arrage
	int actual[3] = {4, 5008, 190};
	Containers::Vector<int> sut(3);
	std::for_each(&actual[0], &actual[0] + sizeof(actual)/sizeof(int), [&sut](int &value) { sut.push_back(value); });
	//Action
	sut.reserve(6);
	std::for_each(&actual[0], &actual[0] + sizeof(actual)/sizeof(int), [&sut](int &value) { sut.push_back(value); });
	//Assert
	for(int idx = 0; idx < (sizeof(actual)/sizeof(int)) * 2; ++idx)
	{
		ASSERT_EQ(actual[idx % 3], sut[idx]);
	}
	
	ASSERT_EQ(6, sut.get_capacity());
}

//Vector::get_size
TEST(VectorGetSizeTestSuite, WhenEmptyVectorSizeEqualToZeroThenOK)
{
	//Arrage
	Containers::Vector<int> sut;
	//Action
	//Assert
	EXPECT_EQ(0, sut.get_size());
}
TEST(VectorGetSizeTestSuite, WhenOneElementVectorSizeEqualToOneThenOK)
{
	//Arrage
	Containers::Vector<int> sut;
	sut.push_back(16);
	//Action
	//Assert
	EXPECT_EQ(1, sut.get_size());
}
TEST(VectorGetSizeTestSuite, WhenManyElementsVectorSizeEqualToElementCountThenOK)
{
	//Arrage
	Containers::Vector<int> sut;
	sut.push_back(16);
	sut.push_back(11);
	sut.push_back(509);
	//Action
	//Assert
	EXPECT_EQ(3, sut.get_size());
}

//Vector::push_back
TEST(VectorPushBackTestSuite, WhenPushedBackLValueElementThenSameElemenInVector)
{
	//Arrage
	int x = 10;
	Containers::Vector<int> sut;
	sut.push_back(x);
	//Act
	//Assert
	ASSERT_EQ(x, sut[0]);
}
TEST(VectorPushBackTestSuite, WhenPushedBackRValueElementThenSameElemenInVector)
{
	//Arrage
	Containers::Vector<int> sut;
	sut.push_back(10);
	//Act
	//Assert
	ASSERT_EQ(10, sut[0]);
}
TEST(VectorPushBackTestSuite, WhenPushedBackElementsThenSameElemensInVector)
{
	//Arrage
	int actual[3] = {4, 5008, 190};
	Containers::Vector<int> sut;
	std::for_each(&actual[0], &actual[0] + 3, [&sut](int &value) { sut.push_back(value); });
	//Action
	//Assert
	for(int idx = 0; idx < sizeof(actual)/sizeof(int); ++idx)
	{
		ASSERT_EQ(actual[idx], sut[idx]);
	}
}
TEST(VectorPushBackTestSuite, WhenExceedsCapacityThenDynamicallyExtendedAndItemsAreTheSame)
{
	//Arrage
	Containers::Vector<int> sut(2);
	sut.push_back(16);
	sut.push_back(11);
	//Action
	sut.push_back(509);
	//Assert
	ASSERT_GT(sut.get_capacity(), 2);
	ASSERT_EQ(16, sut[0]);
	ASSERT_EQ(11, sut[1]);
	ASSERT_EQ(509, sut[2]);
}

//Vector::insert_before
TEST(VectorInsertBeforeTestSuite, WhenRValueBeforeFirstElementInsertedThenSequenceOrderIsCorrect)
{
	//Arrage
	Containers::Vector<int> sut;
	sut.push_back(10);
	sut.push_back(20);
	sut.push_back(30);
	//Act
	sut.insert_before(0, 5);
	//Assert
	//std::for_each(&sut[0], &sut[0] + 4, [](int &value){ std::cout << value << std::endl; });
	ASSERT_EQ(5, sut[0]);
	ASSERT_EQ(10, sut[1]);
	ASSERT_EQ(20, sut[2]);
	ASSERT_EQ(30, sut[3]);
}
TEST(VectorInsertBeforeTestSuite, WhenRValueBeforeMiddleElementInsertedThenSequenceOrderIsCorrect)
{
	//Arrage
	Containers::Vector<int> sut;
	sut.push_back(10);
	sut.push_back(20);
	sut.push_back(30);
	//Act
	sut.insert_before(2, 5);
	//Assert
	//std::for_each(&sut[0], &sut[0] + 4, [](int &value){ std::cout << value << std::endl; });
	ASSERT_EQ(10, sut[0]);
	ASSERT_EQ(20, sut[1]);
	ASSERT_EQ(5, sut[2]);
	ASSERT_EQ(30, sut[3]);
}

TEST(VectorInsertBeforeTestSuite, WhenLValueBeforeFirstElementInsertedThenSequenceOrderIsCorrect)
{
	//Arrage
	int x = 5;
	Containers::Vector<int> sut;
	sut.push_back(10);
	sut.push_back(20);
	sut.push_back(30);
	//Act
	sut.insert_before(0, x);
	//Assert
	//std::for_each(&sut[0], &sut[0] + 4, [](int &value){ std::cout << value << std::endl; });
	ASSERT_EQ(x, sut[0]);
	ASSERT_EQ(10, sut[1]);
	ASSERT_EQ(20, sut[2]);
	ASSERT_EQ(30, sut[3]);
}
TEST(VectorInsertBeforeTestSuite, WhenLValueBeforeMiddleElementInsertedThenSequenceOrderIsCorrect)
{
	//Arrage
	int x = 5;
	Containers::Vector<int> sut;
	sut.push_back(10);
	sut.push_back(20);
	sut.push_back(30);
	//Act
	sut.insert_before(2, x);
	//Assert
	//std::for_each(&sut[0], &sut[0] + 4, [](int &value){ std::cout << value << std::endl; });
	ASSERT_EQ(10, sut[0]);
	ASSERT_EQ(20, sut[1]);
	ASSERT_EQ(x, sut[2]);
	ASSERT_EQ(30, sut[3]);
}
TEST(VectorInsertBeforeTestSuite, WhenLValueEmptyOutOfRangeThenThrow)
{
	//Arrage
	int x = 5;
	Containers::Vector<int> sut;
	//Act
	//Assert
	//std::for_each(&sut[0], &sut[0] + 4, [](int &value){ std::cout << value << std::endl; });
	ASSERT_THROW(sut.insert_before(3, x), std::out_of_range);
	ASSERT_THROW(sut.insert_before(100, x), std::out_of_range);
}
TEST(VectorInsertBeforeTestSuite, WhenLValueNonEmptyOutOfRangeThenThrow)
{
	//Arrage
	int x = 5;
	Containers::Vector<int> sut;
	sut.push_back(10);
	sut.push_back(20);
	sut.push_back(30);
	//Act
	//Assert
	//std::for_each(&sut[0], &sut[0] + 4, [](int &value){ std::cout << value << std::endl; });
	ASSERT_THROW(sut.insert_before(3, x), std::out_of_range);
	ASSERT_THROW(sut.insert_before(100, x), std::out_of_range);
}
TEST(VectorInsertBeforeTestSuite, WhenRValueEmptyOutOfRangeThenThrow)
{
	//Arrage
	Containers::Vector<int> sut;
	//Act
	//Assert
	//std::for_each(&sut[0], &sut[0] + 4, [](int &value){ std::cout << value << std::endl; });
	ASSERT_THROW(sut.insert_before(3, 5), std::out_of_range);
	ASSERT_THROW(sut.insert_before(100, 5), std::out_of_range);
}
TEST(VectorInsertBeforeTestSuite, WhenRValueNonEmptyOutOfRangeThenThrow)
{
	//Arrage
	Containers::Vector<int> sut;
	sut.push_back(10);
	sut.push_back(20);
	sut.push_back(30);
	//Act
	//Assert
	//std::for_each(&sut[0], &sut[0] + 4, [](int &value){ std::cout << value << std::endl; });
	ASSERT_THROW(sut.insert_before(3, 5), std::out_of_range);
	ASSERT_THROW(sut.insert_before(100, 5), std::out_of_range);
}

TEST(VectorInsertBeforeTestSuite, WhenRValueNotEmptyExceedsCapacityThenThrow)
{
	//Arrage
	Containers::Vector<int> sut(2);
	sut.push_back(16);
	sut.push_back(11);
	//Action
	sut.insert_before(0, 5);
	//Assert
	ASSERT_GT(sut.get_capacity(), 2);
	ASSERT_EQ(5, sut[0]);
	ASSERT_EQ(16, sut[1]);
	ASSERT_EQ(11, sut[2]);
}

TEST(VectorInsertBeforeTestSuite, WhenLValueNotEmptyExceedsCapacityThenDynamicallyExtendedAndItemsAreTheSame)
{
	//Arrage
	int x = 5;
	Containers::Vector<int> sut(2);
	sut.push_back(16);
	sut.push_back(11);
	//Action
	sut.insert_before(0, x);
	//Assert
	ASSERT_GT(sut.get_capacity(), 2);
	ASSERT_EQ(x, sut[0]);
	ASSERT_EQ(16, sut[1]);
	ASSERT_EQ(11, sut[2]);
}

//Vector::remove
TEST(VectorRemoveTestSuite, WhenFirstRemovedThenSequenceOrderIsCorrect)
{
	//Arrage
	Containers::Vector<int> sut;
	sut.push_back(10);
	sut.push_back(20);
	sut.push_back(30);
	//Act
	sut.remove(0);
	//Assert
	//std::for_each(&sut[0], &sut[0] + 2, [](int &value){ std::cout << value << std::endl; });
	ASSERT_EQ(20, sut[0]);
	ASSERT_EQ(30, sut[1]);
}
TEST(VectorRemoveTestSuite, WhenMiddleRemovedThenSequenceOrderIsCorrect)
{
	//Arrage
	Containers::Vector<int> sut;
	sut.push_back(10);
	sut.push_back(20);
	sut.push_back(30);
	//Act
	sut.remove(1);
	//Assert
	//std::for_each(&sut[0], &sut[0] + 2, [](int &value){ std::cout << value << std::endl; });
	ASSERT_EQ(10, sut[0]);
	ASSERT_EQ(30, sut[1]);
}
TEST(VectorRemoveTestSuite, WhenLastRemovedThenSequenceOrderIsCorrect)
{
	//Arrage
	Containers::Vector<int> sut;
	sut.push_back(10);
	sut.push_back(20);
	sut.push_back(30);
	//Act
	sut.remove(2);
	//Assert
	//std::for_each(&sut[0], &sut[0] + 2, [](int &value){ std::cout << value << std::endl; });
	ASSERT_EQ(10, sut[0]);
	ASSERT_EQ(20, sut[1]);
}
TEST(VectorRemoveTestSuite, WhenEmptyOutOfRangeThenThrow)
{
	//Arrage
	Containers::Vector<int> sut;
	//Act
	//Assert
	//std::for_each(&sut[0], &sut[0] + 2, [](int &value){ std::cout << value << std::endl; });
	ASSERT_THROW(sut.remove(0), std::out_of_range);
	ASSERT_THROW(sut.remove(10), std::out_of_range);
}
TEST(VectorRemoveTestSuite, WhenNotEmptyOutOfRangeThenThrow)
{
	//Arrage
	Containers::Vector<int> sut;
	sut.push_back(10);
	sut.push_back(20);
	sut.push_back(30);
	//Act
	//Assert
	//std::for_each(&sut[0], &sut[0] + 2, [](int &value){ std::cout << value << std::endl; });
	ASSERT_THROW(sut.remove(3), std::out_of_range);
}

//Vector::operator[]
TEST(VectorOperatorAccessByIndexTestSuite, WhenOneElementThenZeroIndexElementIsTheSame)
{
	//Arrage
	Containers::Vector<int> sut;
	sut.push_back(16);
	//Action
	//Assert
	ASSERT_EQ(16, sut[0]);
}
TEST(VectorOperatorAccessByIndexTestSuite, WhenSomeElementsThenIndexedElementsAreTheSame)
{
	//Arrage
	int actual[3] = {44, 8904, 18};
	Containers::Vector<int> sut;
	std::for_each(&actual[0], &actual[0] + 3, [&sut](int &value) { sut.push_back(value); });
	//Action
	//Assert
	for(int idx = 0; idx < sizeof(actual)/sizeof(int); ++idx)
	{
		ASSERT_EQ(actual[idx], sut[idx]);
	}
}
TEST(VectorOperatorAccessByIndexTestSuite, WhenAccessingEmptyVectorThenThrowOutOfRangeError)
{
	//Arrage
	Containers::Vector<int> sut;
	//Action
	//Assert
	ASSERT_THROW(sut[0], std::out_of_range);
}
TEST(VectorOperatorAccessByIndexTestSuite, WhenAccessingElementOutOfVectorSizeThenThrowOutOfRangeError)
{
	//Arrage
	Containers::Vector<int> sut;
	sut.push_back(10);
	sut.push_back(42);
	//Action
	//Assert
	ASSERT_THROW(sut[2], std::out_of_range);
}
TEST(VectorOperatorAccessByIndexTestSuite, WhenSettingElementByIndexThenValueIsStored)
{
	//Arrage
	Containers::Vector<int> sut;
	sut.push_back(10);
	//Action
	sut[0] = 42;
	//Assert
	ASSERT_EQ(42, sut[0]);
}

class Item
{
public:
	static int instances_count;
	Item();
	~Item();
};


int Item::instances_count = 0;
Item::Item()
{
	++Item::instances_count;
}
Item::~Item()
{
	--Item::instances_count;
}

TEST(VectorOperatorDestructorTestSuite, WhenVectorDestroyedThenItemsDestructorsCalled)
{
	//Arrage
	Containers::Vector<Item> *items = new Containers::Vector<Item>();
	items->push_back(Item {});	
	items->push_back(Item {});	
	items->push_back(Item {});	
	EXPECT_THAT(Item::instances_count, ::testing::Gt(2));
	delete items;
	ASSERT_EQ(0, Item::instances_count);
}

//VectorItor tests
TEST(VectorItorFirstTestSuite, WhenVectorIsEmptyThenFirstIsNullPtr)
{
	//Arrage
	Containers::Vector<int> vec;
	Containers::VectorItor sut(vec);
	//Act
	//Assert
	ASSERT_EQ(nullptr, sut.first());
}

TEST(VectorItorFirstTestSuite, WhenVectorIsNotEmptyThenFirstIsNotNullPtr)
{
	//Arrage
	Containers::Vector<int> vec;
	vec.push_back(12);
	Containers::VectorItor sut(vec);
	//Act
	//Assert
	ASSERT_NE(nullptr, sut.first());
}

TEST(VectorItorNextTestSuite, WhenVectorIsNotEmptyThenNextIsNotNullPtr)
{
	//Arrage
	Containers::Vector<int> vec;
	vec.push_back(11);
	Containers::VectorItor sut(vec);
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
	Containers::VectorItor sut(vec);
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
	Containers::VectorItor sut(vec);
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
	Containers::VectorItor sut(vec);
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
	Containers::VectorReverseItor sut(vec);
	//Act
	//Assert
	ASSERT_EQ(nullptr, sut.first());
}

TEST(VectorReverseItorFirstTestSuite, WhenVectorIsNotEmptyThenFirstIsNotNullptr)
{
	//Arrage
	Containers::Vector<int> vec;
	vec.push_back(11);
	Containers::VectorReverseItor sut(vec);
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
	Containers::VectorReverseItor sut(vec);
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
