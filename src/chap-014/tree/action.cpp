#include <functional>
#include <string>
#include <iostream>

template <class T, class R, typename ...Args>
class Action
{
	std::function<R ()> _callable;
public:
	Action(T fn, Args... args)
	{
		_callable = std::bind(fn, args...);
	}

	R operator()()
	{
		return _callable();
	}
};

int show_message(std::string message)
{
	std::cout << message << std::endl;
	return 10;
}

int main()
{

	Action<int (std::string), int, std::string> a1 (show_message, std::string("Message to show..."));
	std::cout << a1() << std::endl;

	return 0;
}
