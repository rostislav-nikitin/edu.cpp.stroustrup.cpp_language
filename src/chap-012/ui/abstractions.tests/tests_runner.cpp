#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "system/sharedptr.hpp"

#include "abstractions/idrawcontext.hpp"
#include "abstractions/icolorshape.hpp"
#include "abstractions/idot.hpp"
#include "abstractions/iline.hpp"
#include "abstractions/itriangle.hpp"
#include "abstractions/irectangle.hpp"
#include "abstractions/icircle.hpp"

using namespace UI::System;
using namespace UI::Abstractions;

class DotMock : public IDot
{
public:
	DotMock(Color color, Point position) : IDot(color, position) { }
	MOCK_METHOD(void, draw, (IDrawContext *draw_context), (override));
};

class LineMock : public ILine
{
public:
	LineMock(Color color, Point position_tr, Point position_bl, float size) : ILine(color, position_tr, position_bl, size) { }
	MOCK_METHOD(void, draw, (IDrawContext *draw_context), (override));
	MOCK_METHOD(bool, intersects, (ILine const *line), (const, override));
	MOCK_METHOD(bool, intersects, (ITriangle const *triangle), (const, override));
	MOCK_METHOD(bool, intersects, (IRectangle const *rectangle), (const, override));
	MOCK_METHOD(bool, intersects, (ICircle const *circle), (const, override));
};

class TriangleMock : public ITriangle
{
public:
	TriangleMock(Color color, Point position1, Point position2, Point position3) : ITriangle(color, position1, position2, position3) { }
	MOCK_METHOD(void, draw, (IDrawContext *draw_context), (override));
	MOCK_METHOD(bool, intersects, (ILine const *line), (const, override));
	MOCK_METHOD(bool, intersects, (ITriangle const *triangle), (const, override));
	MOCK_METHOD(bool, intersects, (IRectangle const *rectangle), (const, override));
	MOCK_METHOD(bool, intersects, (ICircle const *circle), (const, override));
};

class RectangleMock : public IRectangle
{
public:
	RectangleMock(Color color, Point position, float width, float height) : IRectangle(color, position, width, height) { }
	MOCK_METHOD(void, draw, (IDrawContext *draw_context), (override));
	MOCK_METHOD(bool, intersects, (ILine const *line), (const, override));
	MOCK_METHOD(bool, intersects, (ITriangle const *triangle), (const, override));
	MOCK_METHOD(bool, intersects, (IRectangle const *rectangle), (const, override));
	MOCK_METHOD(bool, intersects, (ICircle const *circle), (const, override));
};

class CircleMock : public ICircle
{
public:
	CircleMock(Color color, Point position, float radius) : ICircle(color, position, radius) { }
	MOCK_METHOD(void, draw, (IDrawContext *draw_context), (override));
	MOCK_METHOD(bool, intersects, (ILine const *line), (const, override));
	MOCK_METHOD(bool, intersects, (ITriangle const *triangle), (const, override));
	MOCK_METHOD(bool, intersects, (IRectangle const *rectangle), (const, override));
	MOCK_METHOD(bool, intersects, (ICircle const *circle), (const, override));
};

class DoubleDispatchFixture : public testing::Test
{
public:
	DoubleDispatchFixture() : 
			dot_mock(Color(1.f, 1.f, 1.f, 1.f), Point(0.f, 0.f)),
			line_mock(Color(1.f, 1.f, 1.f, 1.f), Point(0.f, 0.f), Point(1.f, 1.f), 1.f),
			triangle_mock(Color(1.f, 1.f, 1.f, 1.f), Point(-1.f, -1.f), Point(0.f, 1.f), Point(1.f, -1.f)),
			rectangle_mock(Color(1.f, 1.f, 1.f, 1.f), Point(-1.f, -1.f), 1.f, 1.f),
			circle_mock(Color(1.f, 1.f, 1.f, 1.f), Point(-1.f, -1.f), 1.f),
			dot_mock_ptr(&dot_mock),
			line_mock_ptr(&line_mock),
			triangle_mock_ptr(&triangle_mock),
			rectangle_mock_ptr(&rectangle_mock),
			circle_mock_ptr(&circle_mock)
		{
		}
protected:
	DotMock dot_mock;
	LineMock line_mock;
	TriangleMock triangle_mock;
	RectangleMock rectangle_mock;
	CircleMock circle_mock;

	IColorShape *dot_mock_ptr;
	IColorShape *line_mock_ptr;
	IColorShape *triangle_mock_ptr;
	IColorShape *rectangle_mock_ptr;
	IColorShape *circle_mock_ptr;
};

//IDot
TEST_F(DoubleDispatchFixture, WhenDotIntersectsAnyThenThrow)
{
	EXPECT_ANY_THROW(dot_mock_ptr->intersects(dot_mock_ptr));
	EXPECT_ANY_THROW(dot_mock_ptr->intersects(line_mock_ptr));
	EXPECT_ANY_THROW(dot_mock_ptr->intersects(triangle_mock_ptr));
	EXPECT_ANY_THROW(dot_mock_ptr->intersects(rectangle_mock_ptr));
	EXPECT_ANY_THROW(dot_mock_ptr->intersects(circle_mock_ptr));
}

TEST_F(DoubleDispatchFixture, WhenAnyIntersectsDotThenThrow)
{
	EXPECT_ANY_THROW(line_mock_ptr->intersects(dot_mock_ptr));
	EXPECT_ANY_THROW(triangle_mock_ptr->intersects(dot_mock_ptr));
	EXPECT_ANY_THROW(rectangle_mock_ptr->intersects(dot_mock_ptr));
	EXPECT_ANY_THROW(circle_mock_ptr->intersects(dot_mock_ptr));
}

//ILine
TEST_F(DoubleDispatchFixture, WhenLineIntersectsLineThenOK)
{
	EXPECT_CALL(line_mock, intersects(&line_mock)).Times(1).WillOnce(::testing::Return(true));

	EXPECT_TRUE(line_mock_ptr->intersects(line_mock_ptr));
}

TEST_F(DoubleDispatchFixture, WhenLineIntersectsTriangleThenOK)
{
	EXPECT_CALL(triangle_mock, intersects(&line_mock)).Times(1).WillOnce(::testing::Return(true));

	EXPECT_TRUE(line_mock_ptr->intersects(triangle_mock_ptr));
}

TEST_F(DoubleDispatchFixture, WhenLineIntersectsRectangleThenOK)
{
	EXPECT_CALL(rectangle_mock, intersects(&line_mock)).Times(1).WillOnce(::testing::Return(true));

	EXPECT_TRUE(line_mock_ptr->intersects(rectangle_mock_ptr));
}

TEST_F(DoubleDispatchFixture, WhenLineIntersectsCircleThenOK)
{
	EXPECT_CALL(circle_mock, intersects(&line_mock)).Times(1).WillOnce(::testing::Return(true));

	EXPECT_TRUE(line_mock_ptr->intersects(circle_mock_ptr));
}

//ITriangle
TEST_F(DoubleDispatchFixture, WhenTriangleIntersectsLineThenOK)
{
	EXPECT_CALL(line_mock, intersects(&triangle_mock)).Times(1).WillOnce(::testing::Return(true));

	EXPECT_TRUE(triangle_mock_ptr->intersects(line_mock_ptr));
}

TEST_F(DoubleDispatchFixture, WhenTriangleIntersectsTriangleThenOK)
{
	EXPECT_CALL(triangle_mock, intersects(&triangle_mock)).Times(1).WillOnce(::testing::Return(true));

	EXPECT_TRUE(triangle_mock_ptr->intersects(triangle_mock_ptr));
}

TEST_F(DoubleDispatchFixture, WhenTriangleIntersectsRectangleThenOK)
{
	EXPECT_CALL(rectangle_mock, intersects(&triangle_mock)).Times(1).WillOnce(::testing::Return(true));

	EXPECT_TRUE(triangle_mock_ptr->intersects(rectangle_mock_ptr));
}

TEST_F(DoubleDispatchFixture, WhenTriangleIntersectsCircleThenOK)
{
	EXPECT_CALL(circle_mock, intersects(&triangle_mock)).Times(1).WillOnce(::testing::Return(true));

	EXPECT_TRUE(triangle_mock_ptr->intersects(circle_mock_ptr));
}

//IRectangle
TEST_F(DoubleDispatchFixture, WhenRectangleIntersectsLineThenOK)
{
	EXPECT_CALL(line_mock, intersects(&rectangle_mock)).Times(1).WillOnce(::testing::Return(true));

	EXPECT_TRUE(rectangle_mock_ptr->intersects(line_mock_ptr));
}

TEST_F(DoubleDispatchFixture, WhenRectangleIntersectsTriangleThenOK)
{
	EXPECT_CALL(triangle_mock, intersects(&rectangle_mock)).Times(1).WillOnce(::testing::Return(true));

	EXPECT_TRUE(rectangle_mock_ptr->intersects(triangle_mock_ptr));
}

TEST_F(DoubleDispatchFixture, WhenRectangleIntersectsRectangleThenOK)
{
	EXPECT_CALL(rectangle_mock, intersects(&rectangle_mock)).Times(1).WillOnce(::testing::Return(true));

	EXPECT_TRUE(rectangle_mock_ptr->intersects(rectangle_mock_ptr));
}

TEST_F(DoubleDispatchFixture, WhenRectangleIntersectsCircleThenOK)
{
	EXPECT_CALL(circle_mock, intersects(&rectangle_mock)).Times(1).WillOnce(::testing::Return(true));

	EXPECT_TRUE(rectangle_mock_ptr->intersects(circle_mock_ptr));
}

//ICircle
TEST_F(DoubleDispatchFixture, WhenCircleIntersectsLineThenOK)
{
	EXPECT_CALL(line_mock, intersects(&circle_mock)).Times(1).WillOnce(::testing::Return(true));

	EXPECT_TRUE(circle_mock_ptr->intersects(line_mock_ptr));
}

TEST_F(DoubleDispatchFixture, WhenCircleIntersectsTriangleThenOK)
{
	EXPECT_CALL(triangle_mock, intersects(&circle_mock)).Times(1).WillOnce(::testing::Return(true));

	EXPECT_TRUE(circle_mock_ptr->intersects(triangle_mock_ptr));
}

TEST_F(DoubleDispatchFixture, WhenCircleIntersectsRectangleThenOK)
{
	EXPECT_CALL(rectangle_mock, intersects(&circle_mock)).Times(1).WillOnce(::testing::Return(true));

	EXPECT_TRUE(circle_mock_ptr->intersects(rectangle_mock_ptr));
}

TEST_F(DoubleDispatchFixture, WhenCircleIntersectsCircleThenOK)
{
	EXPECT_CALL(circle_mock, intersects(&circle_mock)).Times(1).WillOnce(::testing::Return(true));

	EXPECT_TRUE(circle_mock_ptr->intersects(circle_mock_ptr));
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
