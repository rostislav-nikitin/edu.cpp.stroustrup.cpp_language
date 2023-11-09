#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP

#include <vector>

#include "idrawcontext.hpp"
#include "ishape.hpp"

namespace UI
{
	namespace Abstractions
	{
		using namespace UI::Abstractions;

		class CompositeShape: public IShape
		{
		private:
			std::vector<IShape *> _shapes;

		public:
			virtual std::vector<IShape *> get_all();
			virtual IShape *append(IShape *shape);

			void draw(IDrawContext *context) override;

			~CompositeShape();
		};
	}
}

#endif
