#ifndef HOME_HPP
#define HOME_HPP

#include <queue>

namespace Solatire
{
	namespace Engine
	{
		template<class T>
		class Home
		{
			std::queue<T> _items;
		public:
			Home();

			typename std::queue<T>::reference top();
			typename std::queue<T>::size_type size() const;
			void push(typename std::queue<T>::value_type item);
			void pop();

			void reset();
		};

		template<class T>
		Home<T>::Home() : _items()
		{
		}
		template<class T>
		typename std::queue<T>::reference Home<T>::top()
		{
			return _items.front();
		}
		template<class T>
		typename std::queue<T>::size_type Home<T>::size() const
		{
			return _items.size();
		}
		template<class T>
		void Home<T>::push(typename std::queue<T>::value_type item)
		{
			_items.push(item);
		}
		template<class T>
		void Home<T>::pop()
		{
			_items.pop();
		}
		template<class T>
		void Home<T>::reset()
		{
			_items = std::queue<T>();
		}
	}
}

#endif
