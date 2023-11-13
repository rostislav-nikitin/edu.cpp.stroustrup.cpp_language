#include "applicationwindow.hpp"

#include <iostream>

namespace UI
{
	namespace OpenGL
	{
		ApplicationWindow::ApplicationWindow(Point2i top_left, int width, int height, bool antialiasing) : _top_left(top_left), _width(width), _height(height)
		{
			_draw_context = new DrawContext(antialiasing);
			_shapes_root = new CompositeShape();

		}

		Point2i ApplicationWindow::get_top_left()
		{
			return _top_left;
		}

		void ApplicationWindow::set_top_left(Point2i const value)
		{
			_top_left = value;
		}

		int ApplicationWindow::get_width() const
		{
			return _width;
		}

		int ApplicationWindow::get_height() const
		{
			return _height;
		}
		void ApplicationWindow::set_width(int value)
		{
			_width = value;
		}
		void ApplicationWindow::set_height(int value)
		{
			_height = value;
		}

		CompositeShape *ApplicationWindow::get_shapes_root() const
		{
			return _shapes_root;
		}
/*
		Point2i ApplicationWindow::get_bottom_right()
		{
			return _bottom_right;
		}

		void ApplicationWindow::set_bottom_right(Point2i const value)
		{
			_bottom_right = value;
		}

		std::vector<IShape *> ApplicationWindow::get_shapes() const
		{
			return _shapes;
		}

		IShape *ApplicationWindow::add_shape(IShape *shape)
		{
			_shapes.push_back(shape);

			return shape;
		}
*/
		void ApplicationWindow::setup_antialiasing_on()
		{
			// Setup anti-aliasing
			glEnable(GL_POINT_SMOOTH);
			glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		void ApplicationWindow::setup_antialiasing_off()
		{
			// Setup anti-aliasing
			/*
			glEnable(GL_POINT_SMOOTH);
			glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			*/
		}

		void ApplicationWindow::setup_antialiasing()
		{
			if(_draw_context->get_antialiasing())
				setup_antialiasing_on();
			else
				setup_antialiasing_off();
		}

		void ApplicationWindow::check_antialiasing_changed()
		{
			if(_draw_context->get_antialiasing_changed())
			{
				setup_antialiasing();
			}
		}

		void ApplicationWindow::create_window()
		{
			if(!glfwInit())
				exit(EXIT_FAILURE);
			_window = glfwCreateWindow(_width, _height, "Chapter 1: Simple GLFW example", NULL, NULL);

			if(!_window)
			{
				glfwTerminate();
					exit(EXIT_FAILURE);
			}
			glfwMakeContextCurrent(_window);
			setup_antialiasing();

			std::cout << "Windows initialized" << std::endl;
		}

		void ApplicationWindow::draw()
		{
			create_window();

			while(!glfwWindowShouldClose(_window))
			{
				check_antialiasing_changed();

				float ratio;
				int width, height;

				glfwGetFramebufferSize(_window, &width, &height);
				ratio = (float) width / (float) height;

				glViewport(0, 0, width, height);
				glClear(GL_COLOR_BUFFER_BIT);

				// Setup camera matrix
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

				// Draw
				/*
				for(std::vector<IShape *>::iterator it = _shapes.begin(); it != _shapes.end(); ++it)
				{
					(*it)->draw(_draw_context);
				}*/

				_shapes_root->draw(_draw_context);

				// Swap buffers
				glfwSwapBuffers(_window);
				// Poll events
				glfwPollEvents();
			}
		}

		ApplicationWindow::~ApplicationWindow()
		{
/*
			for(std::vector<IShape *>::iterator it = _shapes.begin(); it != _shapes.end(); ++it)
			{
				delete *it;
			}
*/
			glfwDestroyWindow(_window);
			glfwTerminate();

			delete _shapes_root;
			delete _draw_context;

			//exit(EXIT_SUCCESS);

		}
	}
}
