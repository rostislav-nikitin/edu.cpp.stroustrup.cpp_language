#include "compositeshape.hpp"

namespace UI
{
	namespace Abstractions
	{
		std::vector<IShape *> CompositeShape::get_all()
		{
			return _shapes;
		}

		IShape *CompositeShape::append(IShape *shape)
		{
			_shapes.push_back(shape);

			return shape;
		}
	
		void CompositeShape::draw(IDrawContext *draw_context)
		{
			for(std::vector<IShape *>::iterator it = _shapes.begin(); it != _shapes.end(); ++it)
			{
				(*it)->draw(draw_context);
			}
		}	

		CompositeShape::~CompositeShape()
		{
			for(std::vector<IShape *>::iterator it = _shapes.begin(); it != _shapes.end(); it++)
			{
				delete *it;
			}
		}
	}
}
