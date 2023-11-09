#ifndef POINT2I_HPP
#define POINT2I_HPP

namespace UI
{
	namespace Abstractions
	{
		class Point2i
		{
		private:
			int _x;
			int _y;
		public:
			Point2i(int x, int y);

			int get_x() const;
			int get_y() const;

			void set_x(int x);
			void set_y(int y);
		};
	}
}

#endif
