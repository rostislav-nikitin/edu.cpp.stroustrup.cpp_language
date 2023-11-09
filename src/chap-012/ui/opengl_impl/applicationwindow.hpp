#ifndef APPLICATIONWINDOW_HPP
#define APPLICATIONWINDOW_HPP

#include <vector>

#include <cstdlib>
#include <GLFW/glfw3.h>

#include "../abstractions/point2i.hpp"
#include "../abstractions/ishape.hpp"
#include "../abstractions/iapplicationwindow.hpp"
#include "../abstractions/compositeshape.hpp"

#include "drawcontext.hpp"

namespace UI
{
	namespace OpenGL
	{
		using namespace UI::Abstractions;

		class ApplicationWindow: public IApplicationWindow
		{
		private:
			Point2i _top_left;
			int _width;
			int _height;
//			Point2i _bottom_right;
//			std::vector<IShape *> _shapes;
//
			CompositeShape *_shapes_root;
			DrawContext *_draw_context;
			GLFWwindow *_window;

			void setup_antialiasing_on();
			void setup_antialiasing_off();
			void setup_antialiasing();
			void check_antialiasing_changed();
		public:
			ApplicationWindow(Point2i, int width = 800, int height = 600, bool antialiasing = true);
			~ApplicationWindow() override;

			Point2i get_top_left() override;
			void set_top_left(Point2i const) override;

			int get_width() const override;
			int get_height() const override;
			CompositeShape *get_shapes_root() const override;

/*
			Point2i get_bottom_right() override;
			void set_bottom_right(Point2i const) override;

			std::vector<IShape *> get_shapes() const override;
			IShape *add_shape(IShape *shape) override;
*/
			void draw() override;
		};
	}
}

#endif
