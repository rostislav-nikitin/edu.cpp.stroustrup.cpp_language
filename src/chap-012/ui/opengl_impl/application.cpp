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

		ApplicationConfigBuilder &Application::configure()
		{
			return _application_config_builder;
		}

		IApplicationWindow *Application::get_application_window() const
		{
			return _application_window;
		}

		void Application::run()
		{
			ApplicationConfigBuilder::ApplicationConfig app_config = _application_config_builder.build();
			_application_window->set_width(app_config.width);
			_application_window->set_height(app_config.height);
			_application_window->get_shapes_root()->insert_to_begin(app_config.shapes);
 
			_application_window->draw();
		}
	}
}
