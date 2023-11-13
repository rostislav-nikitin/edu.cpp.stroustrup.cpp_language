#include "abstractions/compositeshape.hpp"

#include "opengl_impl/application.hpp"
#include "opengl_impl/dot.hpp"
#include "opengl_impl/line.hpp"
#include "opengl_impl/grid.hpp"
#include "opengl_impl/xycoordinates.hpp"

void demo_dots(UI::Abstractions::IApplicationWindow *window);

int main(int argc, char **argv)
{
	using UI::Abstractions::Color;
	using UI::Abstractions::Point;
	using UI::OpenGL::Grid;
	using UI::OpenGL::XYCoordinates;

	UI::OpenGL::Application app;
	app.configure()
		.set_width(1920)
		.set_height(1080)
		.append(new Grid(Color{0.3f, 0.0f, 0.5f, 1.f}, Point{-1.f, -1.f}, 2.f, 2.f, 1.f, 0.1f, Color(0.15f, 0.0f, 0.3f, 1.0f)))
		.append(new XYCoordinates(Color(0.3f, 0.0f, 0.5f, 1.0f), Point(0.0f, 0.0f), 5.f));

	demo_dots(app.get_application_window());

	app.run();


	return 0;
}

void demo_dots(UI::Abstractions::IApplicationWindow *application_window)
{
	using UI::Abstractions::Color;
	using UI::Abstractions::Point;
	using UI::Abstractions::CompositeShape;
	using UI::OpenGL::Dot;
	using UI::OpenGL::Line;

	CompositeShape *root = application_window->get_shapes_root();

	for(float x = -1.f, size = 10.0f, r = 0.0; x <= 1.f; x += 0.2f, size += 3.f, r += 0.1)
	{
		root->append(new Dot(Color{r, 1.0f - r, 0.5f, 1.f}, Point{x, 0.5f}, size));
	}

	root->append(new Line(Color{1.f, 1.f, 1.f, 1.f}, Point{-1.f, 0.5f}, Point{1.f, 0.5f}, 1.f));
}
