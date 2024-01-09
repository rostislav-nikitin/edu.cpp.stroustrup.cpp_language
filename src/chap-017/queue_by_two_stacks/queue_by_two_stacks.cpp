#include <iostream>
#include <stack>
#include <stdexcept>

template<class T>
class Queue
{
	bool _push_active;

	std::stack<T> _push;
	std::stack<T> _pop;
	
	void move_from_push_to_pop();
	void move_from_pop_to_push();

	template<class U = T>
	void push_internal(U &&value);
public:
	int size() const;
	T& top();
	void push(T &value);
	void push(T &&value);
	void pop();
};

template<class T>
int Queue<T>::size() const
{
	if(_push.size() != 0)
		return _push.size();

	return _pop.size();
}

template<class T>
T& Queue<T>::top()
{
	if(size() == 0)
		throw std::out_of_range("Queue is empty.");

	if(_push_active)
		move_from_push_to_pop();

	return _pop.top();
}

template<class T>
void Queue<T>::push(T& value)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	push_internal(std::forward<T&>(value));
}

template<class T>
void Queue<T>::push(T&& value)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	push_internal(std::forward<T&&>(value));
}

template<class T>
template<class U>
void Queue<T>::push_internal(U &&value)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	if(!_push_active)
		move_from_pop_to_push();

	_push.push(value);
}

template<class T>
void Queue<T>::pop()
{
	if(_push_active)
		move_from_push_to_pop();

	_pop.pop();
}

template<class T>
void Queue<T>::move_from_push_to_pop()
{
	while(_push.size())
	{
		_pop.push(_push.top());
		_push.pop();
	}
	_push_active = false;
}

template<class T>
void Queue<T>::move_from_pop_to_push()
{
	while(_pop.size())
	{
		_push.push(_pop.top());
		_pop.pop();
	}
	_push_active = true;
}

int main()
{
	int x = 50;
	Queue<int> q;
	q.push(10);
	q.push(4);
	q.push(40);
	q.push(x);

	while(q.size())
	{
		std::cout << q.top() << std::endl;
		q.pop();
	}


	return EXIT_SUCCESS;
}
