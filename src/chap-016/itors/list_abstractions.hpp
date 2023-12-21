#ifndef LIST_ABSTRACTIONS_H
#define LIST_ABSTRACTIONS_H

#include <memory>
#include <stdexcept>

#include "itor_abstractions.hpp"

namespace Containers
{
	template<class T>
	class ListItorRefStorage;

	//template<class T>
	template<class T, class Storage>
	class ReadOnlyListItor;

	template<class T>
	class ReadOnlyListReverseItor;

	//List
	template<class T>
	class List
	{
		template<class U, class Storage>
		friend class ReadOnlyListItor;//<T, ListItorRefStorage<T>>;

		friend class ReadOnlyListReverseItor<T>;

		struct Link
		{
			Link *prev;
			Link *next;
			T *value;
		};

		Link *_head;

		Link *get_first() const;
		Link *get_last() const;

		void deep_copy(List<T> const &list);
	public:
		List();
		List(List<T> const &list);
		List(List<T> &list);
		List(List<T> &&list);
		
		List<T> &operator=(List<T> const &list);
		List<T> &operator=(List<T> &list);
		List<T> &operator=(List<T> &&list);

		T *get();
		void put(T *);

		~List();
	};

	template<class T>
	typename List<T>::Link *List<T>::get_first() const
	{
		if(_head == nullptr)
			return nullptr;

		Link *head = _head;
		while(head->prev != nullptr)
			head = head->prev;

		return head;
	}

	template<class T>
	typename List<T>::Link *List<T>::get_last() const
	{
		if(_head == nullptr)
			return nullptr;

		Link *head = _head;
		while(head->next != nullptr)
			head = head->next;

		return head;
	}

	template<class T>
	List<T>::List() : _head(nullptr)
	{
	}

	template<class T>
	List<T>::List(List<T> const &list) : _head(nullptr)
	{
		deep_copy(list);
	}

	template<class T>
	List<T>::List(List<T> &list) : _head(nullptr)
	{
		deep_copy(list);
	}

	template<class T>
	List<T>::List(List<T> &&list) : _head(nullptr)
	{
		_head = list.get_first();
		list._head = nullptr;
	}

	template<class T>
	List<T> &List<T>::operator=(List<T> const &list)
	{
		if(list != this)
		{
			deep_copy(list);
		}
	}
	
	template<class T>
	List<T> &List<T>::operator=(List<T> &list)
	{
		if(list != this)
		{
			deep_copy(list);
		}

		return *this;
	}

	template<class T>
	List<T> &List<T>::operator=(List<T> &&list)
	{
		if(list != this)
		{
			_head = list.get_first();
			list._head = nullptr;
		}

		return *this;
	}

	template<class T>
	void List<T>::deep_copy(List<T> const &list)
	{
		Link *res;
		Link *temp = list.get_first();
		while(temp != nullptr)
		{
			if(_head == nullptr)
				res = _head = new Link{_head, nullptr, temp->value};
			else
				_head = _head->next = new Link{_head, nullptr, temp->value};

			temp = temp->next;
		}

		_head = res;
	}
	
	template<class T>
	List<T>::~List()
	{
		_head = get_last();
		while(_head != nullptr)
		{
			Link *prev = _head->prev;
			delete _head;
			_head = prev;
		}
	}

	template<class T>
	T *List<T>::get()
	{
		if(_head == nullptr)
			throw std::out_of_range("List is empty.");

		return _head->value;
	}

	template<class T>
	void List<T>::put(T *value)
	{
		if(_head == nullptr)
		{
			_head = new Link{nullptr, nullptr, value};
		}
		else
		{
			_head = _head->next = new Link{_head, nullptr, value};
		}
	}

	//Storages
	template<class T>
	class IListStorage
	{
	public:
		virtual List<T> &get() = 0;
	};

	template<class T>
	class ListItorRefStorage : public IListStorage<T>
	{
		List<T> &_list;
	public:
		ListItorRefStorage(List<T> &list);
		List<T> &get() override;
	};

	template<class T>
	ListItorRefStorage<T>::ListItorRefStorage(List<T> &list) : _list(list)
	{
	}

	template<class T>
	List<T> &ListItorRefStorage<T>::get()
	{
		return _list;
	}
	
	template<class T>
	class ListItorValueStorage : public IListStorage<T>
	{
		List<T> _list;
	public:
		ListItorValueStorage(List<T> &list);
		List<T> &get() override;
	};

	template<class T>
	ListItorValueStorage<T>::ListItorValueStorage(List<T> &list) : _list(list)
	{
	}

	template<class T>
	List<T> &ListItorValueStorage<T>::get()
	{
		return _list;
	}

	//Iterator interface
	template<class T>
	class ReadOnlyListReverseItor;

	//template<class T, class Storage = ListItorRefStorage<T>>
	template<class T, class Storage = ListItorValueStorage<T>>
	class ReadOnlyListItor : public Itor<T>
	{
		friend class ReadOnlyListReverseItor<T>;

		Storage _storage;
		typename List<T>::Link *_next;
	public:
		ReadOnlyListItor(Storage storage);
		T *first() override;
		T *next() override;
	};



	//ReadOnlyListItor
	//template<class T>
	template<class T, class Storage>
	ReadOnlyListItor<T, Storage>::ReadOnlyListItor(Storage storage) : _storage(storage), _next(storage.get().get_first())
	{
	}

	//template<class T>
	template<class T, class Storage>
	T *ReadOnlyListItor<T, Storage>::first()
	{
		typename List<T>::Link *res = _storage.get().get_first();
		if(res == nullptr)
			return nullptr;

		_next = res->next;

		return res->value;
	}

	//template<class T>
	template<class T, class Storage>
	T *ReadOnlyListItor<T, Storage>::next()
	{
		if(_next == nullptr)
			return nullptr;

		typename List<T>::Link *res = _next;

		_next = _next->next;

		return res->value;
	}

	template<class T>
	class ReadOnlyListReverseItor : public ReverseItor<T>
	{
		ListItorRefStorage<T> _storage;
		typename List<T>::Link *_next;
	public:
		ReadOnlyListReverseItor(List<T> &list);
		T* first() override;
		T* next() override;
		std::unique_ptr<Itor<T>> get_base() override;
	};

	template<class T>
	ReadOnlyListReverseItor<T>::ReadOnlyListReverseItor(List<T> &list) : _storage(list), _next(list.get_last())
	{
	}

	template<class T>
	T *ReadOnlyListReverseItor<T>::first()
	{
		typename List<T>::Link *res = _storage.get().get_last();
		if(res == nullptr)
			return nullptr;

		_next = res->prev;

		return res->value;
	}

	template<class T>
	T *ReadOnlyListReverseItor<T>::next()
	{
		if(_next == nullptr)
			return nullptr;

		typename List<T>::Link *res = _next;

		_next = _next->prev;

		return res->value;
	}

	template<class T>
	std::unique_ptr<Itor<T>> ReadOnlyListReverseItor<T>::get_base()
	{
		ReadOnlyListItor<T> *res = new ReadOnlyListItor<T>(_storage.get());

		if(res->_next == nullptr)
			res->_next = _storage.get().get_first();
		else
			res->_next = res->_next->next;

		return std::unique_ptr<Itor<T>>(res);
	}
}
#endif
