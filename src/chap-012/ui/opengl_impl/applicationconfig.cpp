#include "applicationconfig.hpp"

namespace UI
{
	namespace OpenGL
	{
		ApplicationConfigBuilder::ApplicationConfigBuilder()
		{
			//_app_config = new ApplicationConfig();
		}

		ApplicationConfigBuilder::~ApplicationConfigBuilder()
		{
			//delete _app_config;;
		}

		ApplicationConfigBuilder &ApplicationConfigBuilder::set_width(int value)
		{
			_app_config.width = value; 

			return *this;
		}
		ApplicationConfigBuilder &ApplicationConfigBuilder::set_height(int value)
		{
			_app_config.height = value; 

			return *this;
		}
		ApplicationConfigBuilder &ApplicationConfigBuilder::append(IShape *shape)
		{
			_app_config.shapes.push_back(shape);

			return *this;
		}

		ApplicationConfigBuilder &ApplicationConfigBuilder::append(std::vector<IShape *> shapes)
		{
			for(std::vector<IShape *>::iterator it = shapes.begin(); it != shapes.end(); ++it)
			{
				_app_config.shapes.push_back(*it);
			}

			return *this;
		}


		ApplicationConfigBuilder::ApplicationConfig ApplicationConfigBuilder::build()
		{
			return _app_config;
		}
	}
}
