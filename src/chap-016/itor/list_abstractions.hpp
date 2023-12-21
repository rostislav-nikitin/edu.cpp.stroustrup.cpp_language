#include <stdexcept>

#include "itor_abstractions.hpp"

namespace Containers
{
	//Declarations
	template<class T>
	class ListItor;

	template<class T>
	class List
	{
		friend class ListItor<T>;

		struct Link
		{
			Link *prev;
			Link *next;
			T value;
		};

		Link *_head;
	public:
		List();

		T &get();
		T &put(T value);

		~List();
	};

	//ListItor
	template<class T>
	class ListItor : public Itor<T>
	{
		List<T> &_list;
		typename List<T>::Link *_current;

		typename List<T>::Link *get_head();
	public:
		ListItor(List<T> &list);

		T *first() override;
		T *next() override;
	};

	//Implementation
	//List implementation
	template<class T>
	List<T>::List() : _head(nullptr)
	{
	}

	template<class T>
	T &List<T>::get()
	{
		if(_head == nullptr)
			throw std::out_of_range("List is empty.");

		return _head->value;
	}

	template<class T>
	T &List<T>::put(T value)
	{
		if(_head == nullptr)
			return (_head = new Link{_head, nullptr, value})->value;
		else
			return (_head = _head->next = new Link{_head, nullptr, value})->value;
	}

	template<class T>
	List<T>::~List()
	{
		if(_head == nullptr)
			return;
		
		while(_head->next != nullptr)
			_head = _head->next;

		while(_head != nullptr)
		{
			Link* prev = _head->prev;
			delete _head;
			_head = prev;
		}
	}

	//ListItor implementation
	template<class T>
	ListItor<T>::ListItor(List<T> &list) : _list(list), _current(get_head())
	{
	}

	template<class T>
	typename List<T>::Link *ListItor<T>::get_head()
	{
		typename List<T>::Link *_head = _list._head;

		if(_head == nullptr)
			return nullptr;

		while(_head->prev != nullptr)
			_head = _head->prev;

		return _head;
	}

	template<class T>
	T *ListItor<T>::first()
	{
		_current = get_head();

		if(_current == nullptr)
			return nullptr;

		typename List<T>::Link *result = _current;
		_current = _current->next;

		return &result->value;
	}

	template<class T>
	T *ListItor<T>::next()
	{
		if(_current == nullptr)
			return nullptr;

		typename List<T>::Link *result = _current;
		_current = _current->next;

		return &result->value;
	}
}
