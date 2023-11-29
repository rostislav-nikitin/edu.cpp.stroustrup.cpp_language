//#include <iostream>

template<class T>
class List
{
private:
	struct Link
	{
		Link *_previous;
		Link *_next;
		T _value;

		Link(Link *previous, Link *next, T const &value);
	};
	Link* _head;

public:
	List(T const &head);
	T print_all();
};

template<class T>
List<T>::Link::Link(Link *previous, Link *next, T const &value) : _previous(previous), _next(next), _value(value) {}

template<class T>
List<T>::List(T const& head)
{
	_head = new Link(nullptr, nullptr, head);	
}

template<class T>
T List<T>::print_all()
{
	T result = 0;
	for(Link *current = _head; current != nullptr; current = current->_next)
	{
		//std::cout << current->_value << std::endl;
		result = current->_value;
	}
	return result;
}

int main()
{
	List<int> list(0);
	int result = list.print_all();

	return result;
}
