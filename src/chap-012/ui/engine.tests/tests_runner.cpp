#include <stdexcept>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../system/sharedptr.hpp"

#include "../abstractions/color.hpp"
#include "../abstractions/point.hpp"
#include "../abstractions/idrawcontext.hpp"
#include "../abstractions/idot.hpp"
#include "../abstractions/iline.hpp"

#include "../engine/collisiondetector.hpp"

using namespace UI::System;
using namespace UI::Abstractions;

// Mocks
class DotMock : public IDot
{
public:
	DotMock(Color color, Point position);
	MOCK_METHOD(void, draw, (IDrawContext *draw_context), (override));
};

DotMock::DotMock(Color color, Point position) : IDot(color, position)
{
}

class LineMock : public ILine
{
public:
	LineMock(Color color, Point position_lt, Point position_rb, float size);
	MOCK_METHOD(void, draw, (IDrawContext *draw_context), (override));
};

LineMock::LineMock(Color color, Point position_lt, Point position_rb, float size) : ILine(color, position_lt, position_rb, size)
{
}

class CollisionDetectorFixture : public ::testing::TestWithParam<std::tuple<SharedPtr<IShape>, SharedPtr<IShape>>>
{
};


TEST_P(CollisionDetectorFixture, WhenValidShapesThenTrueTestSuite)
{
	std::tuple<SharedPtr<IShape>, SharedPtr<IShape>> param = GetParam();

	SharedPtr<IShape> shape_lhs = std::get<0>(param);
	SharedPtr<IShape> shape_rhs = std::get<1>(param);

	ASSERT_TRUE(UI::Engine::collision_detect(shape_lhs.get_value(), shape_rhs.get_value()));
}

INSTANTIATE_TEST_SUITE_P(WhenValidShapesThenTrueTestSuite, CollisionDetectorFixture, testing::Values(
						std::make_tuple(
								SharedPtr<IShape>(new LineMock(Color(1.f, 1.f, 1.f, 1.f), Point(0.f, 0.f), Point(1.f, 1.f), 1.f)), 
								SharedPtr<IShape>(new LineMock(Color(1.f, 1.f, 1.f, 1.f), Point(0.f, 1.f), Point(1.f, 0.f), 1.f)))));

// Tests
TEST(CollisionDetectorTestSuite, WhenDotAndAnyThenThrow)
{
 	DotMock dot_mock(Color(1.f, 1.f, 1.f, 1.f), Point(0.f, 0.f));
 	LineMock line_mock(Color(1.f, 1.f, 1.f, 1.f), Point(0.f, 1.f), Point(1.f, 0.f), 1.f);

	ASSERT_THROW(UI::Engine::collision_detect(&dot_mock, &line_mock), std::runtime_error);
}

TEST(CollisionDetectorTestSuite, WhenAnyAndDotThenThrow)
{
 	DotMock dot_mock(Color(1.f, 1.f, 1.f, 1.f), Point(0.f, 0.f));
 	LineMock line_mock(Color(1.f, 1.f, 1.f, 1.f), Point(0.f, 1.f), Point(1.f, 0.f), 1.f);

	ASSERT_THROW(UI::Engine::collision_detect(&line_mock, &dot_mock), std::runtime_error);
}

TEST(CollisionDetectorTestSuite, WhenLineAndLineCrossedThenTrue)
{
 	LineMock line_a_mock(Color(1.f, 1.f, 1.f, 1.f), Point(0.f, 0.f), Point(1.f, 1.f), 1.f);
 	LineMock line_b_mock(Color(1.f, 1.f, 1.f, 1.f), Point(0.f, 1.f), Point(1.f, 0.f), 1.f);

	bool actual = UI::Engine::collision_detect(&line_a_mock, &line_b_mock);

	ASSERT_EQ(true, actual);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
