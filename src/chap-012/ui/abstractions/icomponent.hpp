#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

namespace UI
{
	namespace Abstractions
	{
		class IComponent
		{
		public:
			virtual IComponent[] get_children() = 0;
			virtual void add_child(IComponent *component) = 0;
		};
}
}

#endif
