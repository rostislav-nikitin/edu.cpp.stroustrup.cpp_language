#ifndef COLOR_HPP
#define COLOR_HPP

namespace UI
{
	namespace Abstractions
	{
		class Color
		{
		private:
			float _r;
			float _g;
			float _b;
			float _a;
		public:
			Color(float r, float g, float b, float a);

			float get_r() const;
			float get_g() const;
			float get_b() const;
			float get_a() const;

			void set_r(float r);
			void set_g(float g);
			void set_b(float b);
			void set_a(float a);
		};
	}
}

#endif
