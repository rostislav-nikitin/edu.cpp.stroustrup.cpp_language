#include "abstractions/compositeshape.hpp"

#include "opengl_impl/application.hpp"
#include "opengl_impl/dot.hpp"

void demo_dots(UI::Abstractions::IApplicationWindow *window);

int main(int argc, char **argv)
{
	UI::OpenGL::Application app;
	UI::Abstractions::IApplicationWindow *application_window = app.get_application_window();
	demo_dots(application_window);	

	app.run();

	return 0;
}

void demo_dots(UI::Abstractions::IApplicationWindow *application_window)
{
	using UI::Abstractions::Color;
	using UI::Abstractions::Point;
	using UI::Abstractions::CompositeShape;
	using UI::OpenGL::Dot;

	CompositeShape *root = application_window->get_shapes_root();
	for(float x = -1.f, size = 10.0f, r = 0.0; x <= 1.f; x += 0.2f, size += 3.f, r += 0.1)
	{
		root->append(new Dot(Color{r, 1.0f - r, 0.5f, 1.0f}, Point{x, 0.f}, size));
	}
}
