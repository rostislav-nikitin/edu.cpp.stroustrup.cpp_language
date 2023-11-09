#ifndef POINT_HPP
#define POINT_HPP

namespace UI
{
	namespace Abstractions
	{
		class Point
		{
		private:
			float _x;
			float _y;
		public:
			Point(float x = 0, float y = 0);

			float get_x() const;
			float get_y() const;

			void set_x(float x);
			void set_y(float y);
		};
	}
}

#endif
