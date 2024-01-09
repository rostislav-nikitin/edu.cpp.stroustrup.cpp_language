#ifndef COLUMN_HPP
#define COLUMN_HPP

#include <deque>
#include <stack>

namespace Solatire
{
	namespace Engine
	{
		template<class T>
		class Column
		{
			std::stack<T> _invisible;
			std::deque<T> _visible;
		public:
			Column();
			// Invisible
			typename std::stack<T>::reference invisible_top();
			typename std::stack<T>::size_type invisible_size() const;
			void push_invisible(typename std::stack<T>::value_type item);
			void pop_invisible();

			//Visible
			typename std::deque<T>::reference visible_top();
			typename std::deque<T>::size_type visible_size() const;
			void push_visible(typename std::deque<T>::value_type item);
			void pop_visible();
			typename std::deque<T>::value_type operator[](typename std::deque<T>::size_type index);
		};

		template<class T>
		Column<T>::Column() : _invisible(), _visible()
		{
		}
		// Invisible
		template<class T>
		typename std::stack<T>::reference Column<T>::invisible_top()
		{
			return _invisible.top();
		}
		template<class T>
		typename std::stack<T>::size_type Column<T>::invisible_size() const
		{
			return _invisible.size();
		}
		template<class T>
		void Column<T>::push_invisible(typename std::stack<T>::value_type item)
		{
			_invisible.push(item);
		}
		template<class T>
		void Column<T>::pop_invisible()
		{
			_invisible.pop();
		}

		//Visible
		template<class T>
		typename std::deque<T>::reference Column<T>::visible_top()
		{
			return _visible.back();
		}
		template<class T>
		typename std::deque<T>::size_type Column<T>::visible_size() const
		{
			return _visible.size();
		}
		template<class T>
		void Column<T>::push_visible(typename std::deque<T>::value_type item)
		{
			_visible.push_back(item);
		}
		template<class T>
		void Column<T>::pop_visible()
		{
			_visible.pop_back();
		}
		template<class T>
		typename std::deque<T>::value_type Column<T>::operator[](typename std::deque<T>::size_type index)
		{
			return _visible[index];
		}
	}
}

#endif
