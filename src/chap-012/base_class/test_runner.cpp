#include <iostream>
#include <gtest/gtest.h>

#include "base.hpp"
#include "derived_one.hpp"
#include "derived_two.hpp"

TEST(InheritanceTest, BaseTest)
{
	base b;
	ASSERT_EQ("base", b.iam());
}

TEST(InheritanceTest, DerivedOneTest)
{
	derived_one d1;
	ASSERT_EQ("derived_one", d1.iam());
}

TEST(InheritanceTest, DerivedTwoTest)
{
	derived_two d2;
	ASSERT_EQ("derived_two", d2.iam());
}

TEST(InheritanceTest, PolymorphismTest)
{
	// Polymorphic method calls by pointer
	derived_one d1;

	base *b1 = &d1;
	EXPECT_EQ("derived_one", b1->iam());

	derived_two d2;

	base *b2 = &d2;
	EXPECT_EQ("derived_two", b2->iam());

	// Non-polymorphic (basae method) call by value
	base b11 = d1;
	EXPECT_NE("derived_one", b11.iam());

	base b22 = d2;
	EXPECT_NE("derived_two", b22.iam());
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
