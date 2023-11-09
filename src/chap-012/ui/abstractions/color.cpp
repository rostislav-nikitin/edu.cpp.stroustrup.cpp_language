#include "color.hpp"

namespace UI
{
	namespace Abstractions
	{
		Color::Color(float r, float g, float b, float a) : _r(r), _g(g), _b(b), _a(a) { }

		float Color::get_r() const
		{
			return _r;
		}
		float Color::get_g() const
		{
			return _g;
		}
		float Color::get_b() const
		{
			return _b;
		}
		float Color::get_a() const
		{
			return _a;
		}

		void Color::set_r(float r)
		{
			_r = r;
		}
		void Color::set_g(float g)
		{
			_g = g;
		}
		void Color::set_b(float b)
		{
			_b = b;
		}
		void Color::set_a(float a)
		{
			_a = a;
		}
	}
}
