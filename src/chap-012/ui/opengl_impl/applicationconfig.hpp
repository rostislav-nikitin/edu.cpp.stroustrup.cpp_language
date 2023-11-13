#ifndef APPLICATIONCONFIG_HPP
#define APPLICATIONCONFIG_HPP

#include <vector>

#include "../abstractions/ishape.hpp"

namespace UI
{
	namespace OpenGL
	{
		using namespace UI::Abstractions;

		class ApplicationConfigBuilder
		{
		private:
			struct ApplicationConfig
			{
				int width;
				int height;
				std::vector<IShape *> shapes;
			};

			ApplicationConfig _app_config;

		public:
			ApplicationConfigBuilder();
			~ApplicationConfigBuilder();

			ApplicationConfigBuilder &set_width(int value);
			ApplicationConfigBuilder &set_height(int value);
			ApplicationConfigBuilder &append(IShape *shape);


			ApplicationConfig build();

			friend class Application;
		};
	}
}

#endif
