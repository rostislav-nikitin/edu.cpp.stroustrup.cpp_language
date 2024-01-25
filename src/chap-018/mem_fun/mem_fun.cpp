#include <string>
#include <vector>
#include <iostream>
#include <functional>

template<class T, class R>
class Mem_fun_t : public std::unary_function<T*, R>
{

public:
	typedef R(T::*member_function_type)();
private:
	member_function_type _f;
public:
	Mem_fun_t(member_function_type f) : _f(f) 
	{
	}

	R operator()(T* obj)
	{
		return (obj->*_f)();
	}
};

template<class T, class R>
Mem_fun_t<T, R> Mem_fun(typename Mem_fun_t<T, R>::member_function_type f)
{
	return Mem_fun_t<T, R>(f);
}

template<class T, class R>
class Mem_fun_ref_t : public std::unary_function<T&, R>
{
public:
	typedef R (T::*member_function_type)();
private:
	member_function_type _f;
public:
	Mem_fun_ref_t(member_function_type f) : _f(f)
	{
	}

	R operator()(T& obj)
	{
		return (obj.*_f)();
	}
};

template<class T, class R>
Mem_fun_ref_t<T, R> Mem_fun_ref(typename Mem_fun_ref_t<T, R>::member_function_type f)
{
	return Mem_fun_ref_t<T, R>(f);
}


class Person
{
	std::string _first_name;
public:
	Person(std::string first_name) : _first_name(first_name)
	{
	}

	std::string get_first_name()
	{
		std::cout << _first_name << std::endl;
		return _first_name;
	}
};


int main()
{
	std::vector<Person *> persons_ptrs = { new Person("John"), new Person("Mark"), new Person("Nicola") };
	std::for_each(persons_ptrs.begin(), persons_ptrs.end(), Mem_fun<Person, std::string>(&Person::get_first_name));

	std::vector<Person> persons = { Person("John"), Person("Mark"), Person("Nicola") };
	std::for_each(persons.begin(), persons.end(), Mem_fun_ref<Person, std::string>(&Person::get_first_name));

	return 0;
}
