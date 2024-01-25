#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

class Person
{
	std::string _name;
public:
	Person(std::string name) : _name(name) { }

	std::string get_name() const
	{
		return _name;
	}
};

class Club
{
	int _id;
	std::string _name;
	std::vector<Person *> _members;

	
	class member_deleter
	{
	public:
		void operator()(Person *person)
		{
			delete person;
		}
	};
public:
	Club() = default;
	Club(int id, std::string name) : _id(id), _name(name), _members(){ }
	~Club()
	{
		std::for_each(_members.begin(), _members.end(), member_deleter());
	}


	int get_id() const
	{
		return _id;
	}

	std::string get_name() const
	{
		return _name;
	}

	std::vector<Person *>& get_members()
	{
		return _members;
	}

	void add_member(Person *person)
	{
		_members.push_back(person);
	}
};
/*
class add_members : public std::binary_function<Person, std::vector<Person>&, void>
{
	std::vector<Person> _members;
public:
	void add_members(std::vector<Person> &initial) : _members(initial) { }
	void operator()(Person const &person)
	{
	}
};
*/
class extract_members : public std::unary_function<Club, void>
{
	std::vector<Person *> &_persons;
public:
	extract_members(std::vector<Person *> &initial) : _persons(initial) { }
	void operator()(Club *club)
	{
		std::copy(club->get_members().begin(), club->get_members().end(), std::back_inserter<std::vector<Person *>>(_persons));
	}
};

void extract(std::vector<Club *> &clubs, std::vector<Person *> &accumulator)
{
	std::for_each(clubs.begin(), clubs.end(), extract_members(accumulator));
}

template<class T>
class print_name : std::unary_function<std::ostream, T>
{
	std::ostream &_stream;
public:
	print_name(std::ostream &stream) : _stream(stream) { }

	std::ostream& operator()(T *item)
	{
		_stream << item->get_name() << std::endl;

		return _stream;
	}
};

int main()
{
	Club maiami_club(1, "Maiami Golf Club");
	maiami_club.add_member(new Person("John Smith"));
	maiami_club.add_member(new Person("Paul McCartney"));

	Club new_york_club(2, "New York Golf Club");
	new_york_club.add_member(new Person("Derek McColins"));
	new_york_club.add_member(new Person("Michael Doe"));

	std::vector<Club *> clubs ({&maiami_club, &new_york_club});
	std::vector<Person *> persons;

	extract(clubs, persons);
	std::for_each(persons.begin(), persons.end(), print_name<Person>(std::cout));

	return EXIT_SUCCESS;
}
