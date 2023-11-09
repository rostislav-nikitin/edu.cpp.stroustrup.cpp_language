#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <GLFW/glfw3.h>

#include "../abstractions/iapplication.hpp"

#include "applicationwindow.hpp"

namespace UI
{
	namespace OpenGL
	{
		using namespace UI::Abstractions;

		class Application : public IApplication
		{
		private:
			ApplicationWindow *_application_window;

		public:
			Application();
			~Application();	

			IApplicationWindow *get_application_window() const override;

			void run() override;
		};
	}
}

#endif
