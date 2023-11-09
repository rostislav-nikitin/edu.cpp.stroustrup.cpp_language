#ifndef DOT_HPP
#define DOT_HPP

#include "../abstractions/idot.hpp"
#include "../abstractions/color.hpp"
#include "../abstractions/point.hpp"

namespace UI
{
	namespace OpenGL
	{
		using namespace UI::Abstractions;

		class Dot : public IDot
		{
		private:
			float _size;	

		public:
			Dot(Color const, Point const, float _size = 1.0);

			virtual void draw(IDrawContext *context) override;
		};
	}
}

#endif
