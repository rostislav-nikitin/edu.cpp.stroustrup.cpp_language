#ifndef IAPPLICATION_HPP
#define IAPPLICATION_HPP

#include "iapplicationwindow.hpp"

namespace UI
{
	namespace Abstractions
	{
		class IApplication
		{
		public:
			virtual IApplicationWindow *get_application_window() const = 0;

			virtual void run() = 0;
		};
	}
}

#endif
