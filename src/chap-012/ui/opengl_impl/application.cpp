#include "application.hpp"

namespace UI
{
	namespace OpenGL
	{
			Application::Application()
			{
				_application_window = new ApplicationWindow(Point2i(0, 0));
			}

			Application::~Application()
			{
				delete _application_window;
			}

			IApplicationWindow *Application::get_application_window() const
			{
				return _application_window;
			}

			void Application::run()
			{
				_application_window->draw();
			}
	}
}
