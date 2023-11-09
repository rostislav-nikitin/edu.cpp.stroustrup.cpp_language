#ifndef DRAWCONTEXT_HPP
#define DRAWCONTEXT_HPP

#include "../abstractions/idrawcontext.hpp"

namespace UI
{
	namespace OpenGL
	{
		using namespace UI::Abstractions;

		class DrawContext : public IDrawContext
		{
		private:
			bool _antialiasing;
			mutable bool _antialiasing_changed;

		public:
			DrawContext(bool antialiasing = false);

			bool get_antialiasing() const;
			void set_antialiasing(bool value);

			bool get_antialiasing_changed() const;
		};
	}
}

#endif
