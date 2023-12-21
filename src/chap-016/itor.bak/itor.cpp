#include <iostream>
#include <algorithm>

//Containers
//Vector Container
template<class T>
class Vector
{
	T *_values;
	size_t _index;
public:
	friend class VectprItor;

	explicit Vector(size_t n);
	~Vector();
	T& operator[](size_t index);
	size_t size() const;
	void push_back(T const &value);
};

template<class T>
Vector<T>::Vector(size_t n) :_values(new T[n]), _index(0)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<class T>
Vector<T>::~Vector()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	delete[] _values;
}

template<class T>
T& Vector<T>::operator[](size_t index)
{
	if(_index < index)
		_index = index + 1;
	return _values[index];
}

template<class T>
size_t Vector<T>::size() const
{
	return _index;
}
template<class T>
void Vector<T>::push_back(T const &value)
{
	_values[_index++] = value;
}


//List Container
template<class T>
class ListItor;


template<class T>
class List
{
	friend class ListItor<T>;
	struct Link
	{
		Link* prev;
		Link* next;
		T value;
	};

	Link *_head;
public:
	List();
	T &put(T);
	T &get();
	~List();

};

template<class T>
List<T>::List() : _head(nullptr)
{ 
	std::cout << __PRETTY_FUNCTION__ << std::endl;
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
		Link *prev = _head->prev;
		//std::cout << _head->value << std::endl;
		delete _head;
		_head = prev;
	}

	std::cout << __PRETTY_FUNCTION__ <<std::endl;
}

template<class T>
T& List<T>::put(T value)
{
	if(_head == nullptr)
		return (_head = new Link {nullptr, nullptr, value})->value;
	else
	{
		_head->next = new Link {_head, nullptr, value};
		_head = _head->next;
		return _head->value;
	}
}

template<class T>
T& List<T>::get()
{
	return _head->value;
}

//Iterators
template<class T>
class Itor
{
public:
	virtual T *first() = 0;
	virtual T *next() = 0;
	virtual ~Itor() {};
};
//Vector Iterator
template<class T>
class VectorItor : public Itor<T>
{
	Vector<T> &_vec;
	size_t _current;
public:
	VectorItor(Vector<T> &vec);
	virtual T *first() override;
	virtual T *next() override;
};
template<class T>
VectorItor<T>::VectorItor(Vector<T> &vec) : _vec(vec), _current(0)
{
}
template<class T>
T *VectorItor<T>::first()
{
	return &_vec[0];
}
template<class T>
T *VectorItor<T>::next()
{
	if((_current + 1) >= _vec.size())
		return nullptr;

	return &_vec[0] + (++_current);
}

// List Iterator
template<class T>
class ListItor : public Itor<T>
{
	List<T> &_list;
	typename List<T>::Link *_current;
	typename List<T>::Link *head();
public:
	ListItor(List<T> &);
	T *first() override;
	T *next() override;
};

template<class T>
ListItor<T>::ListItor(List<T> &list) : _list(list), _current(head())
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<class T>
typename List<T>::Link *ListItor<T>::head()
{
	typename List<T>::Link *head(_list._head);

	if(head == nullptr)
		return nullptr;

	while(head->prev != nullptr)
		head = head->prev;

	return head;
}

template<class T>
T *ListItor<T>::first()
{
	typename List<T>::Link *head(_list._head);

	if(head == nullptr)
		return nullptr;

	while(head->prev != nullptr)
		head = head->prev;

	return &head->value;
}


template<class T>
T *ListItor<T>::next()
{
	if(_current != nullptr)
		_current = _current->next;

	if(_current == nullptr)
		return nullptr;

	return &_current->value;	
}


template<class T>
void show(Itor<T> &itor)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	T *current = itor.first();

	while(current != nullptr)
	{
		std::cout << *current << std::endl;
		current = itor.next();
	}

}

int main()
{

	Vector<int> vec(10);

	vec[0] = 5;
	vec[1] = 10;
	vec.push_back(33);

//	std::for_each(&vec[0], &vec[0] + vec.size(), [](int x) { std::cout << x << std::endl; });

	VectorItor<int> vec_itor(vec);

	show(vec_itor);

	List<int> lst;
	lst.put(10);
	lst.put(20);
	lst.put(5);

	ListItor<int> lst_itor(lst);
	show(lst_itor);

	return 0;
}
