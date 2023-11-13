#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP

#include <vector>
#include <algorithm>

#include "idrawcontext.hpp"
#include "ishape.hpp"

namespace UI
{
	namespace Abstractions
	{
		using namespace UI::Abstractions;

		class CompositeShape: public IShape
		{
		protected:
			std::vector<IShape *> _shapes;

		public:
			virtual std::vector<IShape *> get_all();
			virtual IShape *append(IShape *shape);
			virtual void append(std::vector<IShape *> shapes);
			void insert_to_begin(std::vector<IShape *> shapes);

			void draw(IDrawContext *context) override;

			~CompositeShape();
		};
	}
}

#endif
