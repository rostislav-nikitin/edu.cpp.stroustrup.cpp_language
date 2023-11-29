#include <vector>
#include <optional>
#include <iostream>
#include <cstring>

template<class TPairKey, class TPairValue>
struct Pair
{
	TPairKey key;
	TPairValue value;

	Pair(TPairKey key, TPairValue value) : key(key), value(value) {}
};

template<class TKey, class TValue>
class Map
{
private:
	std::vector<Pair<TKey, TValue>> _values;

public:
	static Pair<TKey, TValue> create_pair(TKey key, TValue value) { return Pair(key, value);  } 


	std::optional<Pair<TKey, TValue> *> get_pair(TKey key);

	void push_back(Pair<TKey, TValue> pair);

	void print_all()
	{
		for(typename std::vector<Pair<TKey, TValue>>::iterator it = _values.begin(); it != _values.end(); ++it)
		{
			std::cout << "Key=" << it->key << "\t Value=" << it->value << std::endl;
		}
	}

};


template<class TKey, class TValue>
std::optional<Pair<TKey, TValue> *> Map<TKey, TValue>::get_pair(TKey key)
{
	for(typename std::vector<Pair<TKey, TValue>>::iterator it = _values.begin(); it != _values.end(); ++it)
	{
		if(it->key == key)
			return std::optional<Pair<TKey, TValue> *>(&(*it));
	}
	return {};
}

template<class TKey, class TValue>
void Map<TKey, TValue>::push_back(Pair<TKey, TValue> pair)
{
	std::optional<Pair<TKey, TValue> *> existing_pair = get_pair(pair.key);
	if(existing_pair.has_value())
	{
		existing_pair.value()->value = pair.value;
	}
	else
	{
		_values.push_back(pair);
	}
}

template<class TValue>
class Map<char const *, TValue>
{
private:
	std::vector<Pair<char const *, TValue>> _values;

public:
	static Pair<char const *, TValue> create_pair(char const *key, TValue value) { return Pair(key, value);  } 


	std::optional<Pair<char const *, TValue> *> get_pair(char const *key);

	void push_back(Pair<char const *, TValue> pair);

	void print_all()
	{
		for(typename std::vector<Pair<char const *, TValue>>::iterator it = _values.begin(); it != _values.end(); ++it)
		{
			std::cout << "Key=" << it->key << "\t Value=" << it->value << std::endl;
		}
	}

};

template<class TValue>
std::optional<Pair<char const *, TValue> *> Map<char const *, TValue>::get_pair(char const *key)
{
	for(typename std::vector<Pair<char const *, TValue>>::iterator it = _values.begin(); it != _values.end(); ++it)
	{
		if(strcmp(it->key,key) == 0)
		{
//			std::cout << "it->key=" << it->key << "\t key=" << key << "\t strcmp=" << strcmp(it->key, key) << std::endl;
			return std::optional<Pair<char const *, TValue> *>(&(*it));
		}
	}
	return {};
}
template<class TValue>
void Map<char const *, TValue>::push_back(Pair<char const *, TValue> pair)
{
	std::optional<Pair<char const *, TValue> *> existing_pair = get_pair(pair.key);
	if(existing_pair.has_value())
	{
		existing_pair.value()->value = pair.value;
	}
	else
	{
		_values.push_back(pair);
	}
}




int main()
{
	Map<std::string, int> values;
	values.push_back(Map<std::string, int>::create_pair("Dog", 10));
	values.push_back(Map<std::string, int>::create_pair("Cat", 20));
	values.push_back(Map<std::string, int>::create_pair("Cat", 30));
	values.print_all();

//	char *cat = "Cat";
//	*cat = "Cat2";
	char cat[] {'C', 'a', 't', '\0'};
	Map<char const *, int> cvalues;
	cvalues.push_back(Map<char const *, int>::create_pair("Dog", 10));
	cvalues.push_back(Map<char const *, int>::create_pair("Cat", 20));
	cvalues.push_back(Map<char const *, int>::create_pair(cat, 40));
	cvalues.print_all();

	return 0;
}
