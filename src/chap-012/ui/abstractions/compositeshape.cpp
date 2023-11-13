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
		void CompositeShape::append(std::vector<IShape *> shapes)
		{
			for(std::vector<IShape *>::iterator it = shapes.begin(); it != shapes.end(); ++it)
			{
				append(*it);
			}
		}
	
		void CompositeShape::insert_to_begin(std::vector<IShape *> shapes)
		{
			std::vector<IShape *> reversed = shapes;
			std::reverse(reversed.begin(), reversed.end());

			for(std::vector<IShape *>::iterator it = reversed.begin(); it != reversed.end(); ++it)
			{
				_shapes.insert(_shapes.begin(), *it);
			}
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
