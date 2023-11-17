#include <vector>

#include "abstractions/icolorshape.hpp"
#include "abstractions/compositeshape.hpp"

#include "opengl_impl/application.hpp"
#include "opengl_impl/dot.hpp"
#include "opengl_impl/line.hpp"
#include "opengl_impl/triangle.hpp"
#include "opengl_impl/rectangle.hpp"
#include "opengl_impl/circle.hpp"
#include "opengl_impl/grid.hpp"
#include "opengl_impl/xycoordinates.hpp"

void test_double_dispatch();
std::vector<UI::Abstractions::IShape *> gen_shapes();

int main(int argc, char **argv)
{
	using UI::Abstractions::Color;
	using UI::Abstractions::Point;
	using UI::OpenGL::Grid;
	using UI::OpenGL::XYCoordinates;

	test_double_dispatch();

	UI::OpenGL::Application app;
	app.configure()
		.set_width(1920)
		.set_height(1080)
		.append(new Grid(Color{0.3f, 0.0f, 0.5f, 1.f}, Point{-1.f, -1.f}, 2.f, 2.f, 1.f, 0.1f, Color(0.15f, 0.0f, 0.3f, 1.0f)))
		.append(new XYCoordinates(Color(0.3f, 0.0f, 0.5f, 1.0f), Point(0.0f, 0.0f), 5.f))
		.append(gen_shapes());

	app.run();

	return 0;
}

void test_double_dispatch()
{
	using UI::Abstractions::Color;
	using UI::Abstractions::Point;
	using UI::OpenGL::Line;
	using UI::OpenGL::Triangle;
	using UI::OpenGL::IColorShape;
	
	Line line(Color{1.f, 1.f, 1.f, 0.5f}, Point{-0.8f, 0.5f}, Point{-0.2f, 0.5f}, 1.f);
	Triangle triangle(Color(0.f, 0.f, 1.f, 0.5f), Point(0.2f, 0.2f), Point(0.5f, 0.8f), Point(0.8f, 0.2f));

	IColorShape &color_shape_line = line;
	IColorShape &color_shape_triangle = triangle;

	color_shape_line.intersects(&color_shape_triangle);
}

std::vector<UI::Abstractions::IShape *> gen_shapes()
{
	using UI::Abstractions::Color;
	using UI::Abstractions::Point;
	using UI::Abstractions::CompositeShape;
	using UI::OpenGL::Dot;
	using UI::OpenGL::Line;
	using UI::OpenGL::Triangle;
	using UI::OpenGL::Rectangle;
	using UI::OpenGL::Circle;

	std::vector<UI::Abstractions::IShape *> result;

	for(float x = -0.8f, size = 10.0f, r = 0.0; x <= -0.2f; x += 0.2f, size += 15.f, r += 0.1)
	{
		result.push_back(new Dot(Color{r, 1.0f - r, 0.5f, 0.5f}, Point{x, 0.5f}, size));
	}

	result.push_back(new Line(Color{1.f, 1.f, 1.f, 0.5f}, Point{-0.8f, 0.5f}, Point{-0.2f, 0.5f}, 1.f));
	result.push_back(new Triangle(Color(0.f, 0.f, 1.f, 0.5f), Point(0.2f, 0.2f), Point(0.5f, 0.8f), Point(0.8f, 0.2f)));
	result.push_back(new Rectangle(Color(1.f, 0.f, 0.f, 0.5f), Point(0.2f, -0.2f), 0.6f, 0.6f));
	result.push_back(new Circle(Color(0.f, 1.f, 0.f, 0.5f), Point(-0.5f, -0.5f), 0.3f));

	return result;
}
