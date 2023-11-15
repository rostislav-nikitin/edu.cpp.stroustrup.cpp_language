#ifndef COLLISIONDETECTOR_HPP
#define COLLISIONDETECTOR_HPP

#include <stdexcept>
#include <iostream>

#include "../abstractions/iline.hpp"
#include "../abstractions/itriangle.hpp"
#include "../abstractions/irectangle.hpp"
#include "../abstractions/icircle.hpp"

namespace UI
{
	namespace Engine
	{
		using namespace UI::Abstractions;

		// Visitor pattern
		class CollisionDetector
		{
		private:
			bool _detect(ILine const *, ILine const *) const;
			bool _detect(ITriangle const *, ITriangle const *) const;
			bool _detect(IRectangle const *, IRectangle const *) const;
			bool _detect(ICircle const *, ICircle const *) const;

			bool _detect(ILine const *, ITriangle const *) const;
			bool _detect(ILine const *, IRectangle const *) const;
			bool _detect(ILine const *, ICircle const *) const;

			bool _detect(ITriangle const *, IRectangle const *) const;
			bool _detect(ITriangle const *, ICircle const *) const;

			bool _detect(IRectangle const *, ICircle const *) const;

		public:
			bool detect(ILine const *, ILine const *) const;
			bool detect(ILine const *, ITriangle const *) const;
			bool detect(ILine const *, IRectangle const *) const;
			bool detect(ILine const *, ICircle const *) const;

			bool detect(ITriangle const *, ILine const *) const;
			bool detect(ITriangle const *, ITriangle const *) const;
			bool detect(ITriangle const *, IRectangle const *) const;
			bool detect(ITriangle const *, ICircle const *) const;

			bool detect(IRectangle const *, ILine const *) const;
			bool detect(IRectangle const *, ITriangle const *) const;
			bool detect(IRectangle const *, IRectangle const *) const;
			bool detect(IRectangle const *, ICircle const *) const;

			bool detect(ICircle const *, ILine const *) const;
			bool detect(ICircle const*, ITriangle const*) const;
			bool detect(ICircle const *, IRectangle const *) const;
			bool detect(ICircle const *, ICircle const *) const;
		};

		bool collision_detect(IShape const *, IShape const *);
	}
}

#endif
