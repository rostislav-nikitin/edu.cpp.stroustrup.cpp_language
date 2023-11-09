#include "drawcontext.hpp"

namespace UI
{
	namespace OpenGL
	{
		DrawContext::DrawContext(bool antialiasing) : _antialiasing(antialiasing), _antialiasing_changed(false) { }

 		bool DrawContext::get_antialiasing() const
		{
			_antialiasing_changed = false;
			return _antialiasing;
		}

		void DrawContext::set_antialiasing(bool value)
		{
			_antialiasing_changed = true;
			_antialiasing = value;
		}

		bool DrawContext::get_antialiasing_changed() const
		{
			return _antialiasing_changed;
		}

	}
}
