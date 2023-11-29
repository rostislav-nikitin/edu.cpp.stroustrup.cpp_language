#include <iostream>
/*

template<class T>
struct Element<T>
{
	T value;
	Element<T> *prev;
	Element<T> *next;
};

template<class E>
struct IntrusiveList
{
	E _head;
	E get_next() { return _head.next;  } 
};

//
template<class T>
struct NonIntrusiveListInStr
{
	struct Link
	{
		T value;
		Lint *prev;
		Link *next;
	}
}
//
template<class T>
struct NonIntrusiveListInh
{
	struct Link<U>
	{
		U *prev;
		U *next;
	}

	struct Element : Link<Element>
	{
		T& value;
	}
};


struct Link
{
	Link *prev;
	Link *next;
}
*/

template<class T>
class List
{
private:
	template<class U>
	struct Link
	{
		U *_previous;
		U *_next;

		U &self()
		{
			return static_cast<U &>(*this);
		}

		Link(U *previous, U *next);
	};

	struct TLink : Link<TLink>
	{
		T _value;

		TLink(TLink *previous, TLink *next, T const &value);
	};

	TLink *_head;
public:
	List(T const &value);

	void print_all();
};

template<class T>
template<class U>
List<T>::Link<U>::Link(U *previous, U *next) : _previous(previous), _next(next) {}

template<class T>
List<T>::TLink::TLink(TLink *previous, TLink *next, T const &value) : Link<TLink>(previous, next), _value(value) {}

template<class T>
List<T>::List(T const &value) : _head(new TLink(nullptr, nullptr, value)) { }

template<class T>
void List<T>::print_all()
{
	for(TLink *current = _head; current != nullptr; current = current->_next)
	{
		std::cout << current->self()._value << std::endl;
	}
}
