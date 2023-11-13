#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <GLFW/glfw3.h>

#include "../abstractions/iapplication.hpp"

#include "applicationconfig.hpp"
#include "applicationwindow.hpp"

namespace UI
{
	namespace OpenGL
	{
		using namespace UI::Abstractions;

		class Application : public IApplication
		{
		private:
			ApplicationConfigBuilder _application_config_builder;
			ApplicationWindow *_application_window;

		public:
			Application();
			~Application();	

			ApplicationConfigBuilder &configure();

			IApplicationWindow *get_application_window() const override;

			void run() override;
		};
	}
}

#endif
