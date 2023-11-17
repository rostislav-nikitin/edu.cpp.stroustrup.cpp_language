#include <vector>
#include <iostream>

class Location
{
public:
	Location *get_parent();

	std::vector<Location *> get_locations();
	std::vector<Object *> get_objects();
	std::vector<Person *> get_persons();
	

	void pick_up(Object *object);
	void put(Object *object);

	void enter(Person *person);
	void leave(Person *person);
};

class Interactions
{
};

class Person
{
public:
	float get_health_level() const;
	void set_health_level(float value);

	bool can_interact_with(Person *person);
	Interaction *interact_with(Person *person);

	Location *get_location();
	void move_to(Location *to);
};

class Warrior : public Person
{
public:
	std::vector<Object *> get_owned_objects();

	void pick_up(Object *object);
	void put(Object *object);
};

class Monster : public Person
{
public:
};

class Object
{
public:
	Location *get_location();
	void set_location(Location const *person);
	bool has_location() const;

	Person *get_owner();
	void set_owner(Person const *person);
	bool has_owner() const;
};
