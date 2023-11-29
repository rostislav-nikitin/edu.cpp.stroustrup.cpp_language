#include <vector>
#include <optional>
#include <iostream>
#include <cstring>

template<class T>
struct Comparer
{
	bool compare(T lhv, T rhv)
	{
		return lhv == rhv;
	}
};

template<class T>
struct Comparer<T&>
{
	bool compare(T lhv, T rhv)
	{
		return lhv == rhv;
	}
};

template<>
struct Comparer<char const *>
{
	bool compare(char const *lhv, char const *rhv)
	{
		return strcmp(lhv, rhv) == 0;
	}
};

template<class T>
bool compare(T lhv, T rhv)
{
	return lhv == rhv;
}

template<>
bool compare(char const *lhv, char const *rhv)
{
	return strcmp(lhv, rhv) == 0;
}

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

	template<class TKeyType>
	friend bool key_compare(TKeyType lhv, TKeyType rhv);
};

template<class TKey>
bool key_compare(TKey lhv, TKey rhv)
{
	return lhv == rhv;
}

template<>
bool key_compare(char const *lhv, char const *rhv)
{
	return strcmp(lhv, rhv) == 0;
}


template<class TKey, class TValue>
std::optional<Pair<TKey, TValue> *> Map<TKey, TValue>::get_pair(TKey key)
{
	for(typename std::vector<Pair<TKey, TValue>>::iterator it = _values.begin(); it != _values.end(); ++it)
	{
		//Comparer<TKey> comparer;
		//if(comparer.compare(it->key, key))
		if(key_compare(it->key, key))
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

class A
{
public:
	A() = delete;
	A(int i);
};

A::A(int i)
{
}

int main()
{
	Map<std::string, int> values;
	values.push_back(Map<std::string, int>::create_pair("Dog", 10));
	values.push_back(Map<std::string, int>::create_pair("Cat", 20));
	values.push_back(Map<std::string, int>::create_pair("Cat", 30));
	values.print_all();

	char cat[] {'C', 'a', 't', '\0'};
	Map<char const *, int> cvalues;
	cvalues.push_back(Map<char const *, int>::create_pair("Dog", 10));
	cvalues.push_back(Map<char const *, int>::create_pair("Cat", 20));
	cvalues.push_back(Map<char const *, int>::create_pair(cat, 40));
	cvalues.print_all();

	Map<std::string, A> avalues;
	avalues.push_back(Map<std::string, A>::create_pair("k1", 10));

	return 0;
}
