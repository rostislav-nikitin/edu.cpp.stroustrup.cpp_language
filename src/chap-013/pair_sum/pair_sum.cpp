#include <iostream>
#include <vector>
#include <optional>

template<class TKey, class TValue>
bool exists_key(std::vector<std::pair<TKey, TValue>> &values, TKey &key);

template<class TKey, class TValue>
std::optional<std::pair<TKey, TValue> *> get_pair(std::vector<std::pair<TKey, TValue>> &values, TKey &key);

template<class TKey, class TValue>
std::vector<std::pair<TKey, TValue>> sum(std::vector<std::pair<TKey, TValue>> &values)
{
	std::vector<std::pair<TKey, TValue>> result;
	for(typename std::vector<std::pair<TKey, TValue>>::iterator it = values.begin(); it != values.end(); ++it)
	{
		std::optional<std::pair<TKey, TValue> *> pair= get_pair(result, it->first);

		if(pair)
		{
			if(pair.has_value())
				pair.value()->second += it->second;
		}
		else
		{
			result.push_back(std::make_pair(it->first, it->second));
		}
	}

	return result;
}

template<class TKey, class TValue>
std::optional<std::pair<TKey, TValue> *> get_pair(std::vector<std::pair<TKey, TValue>> &values, TKey &key)
{
	for(typename std::vector<std::pair<TKey, TValue>>::iterator it = values.begin(); it != values.end(); ++it)
	{
		if(it->first == key)
			return std::optional<std::pair<TKey, TValue> *>(&(*it));
	}
	return {};
}

template<class TKey, class TValue>
void print(std::vector<std::pair<TKey, TValue>> values)
{
	for(typename std::vector<std::pair<TKey, TValue>>::iterator it = values.begin(); it != values.end(); ++it)
	{
		std::cout << "Key=" << it->first << "\tValue=" << it->second << std::endl;
	}
}


int main()
{
	std::vector<std::pair<std::string, float>> values{std::pair{"BMW", 500.f}, std::pair{"Mercedes", 105.5f}, std::pair{"BMW", 25.25f}};

	std::cout << std::endl << "Original" << std::endl;
	print(values);

	std::vector<std::pair<std::string, float>> aggregated_values = sum(values);

	std::cout << std::endl << "Aggregated(Sum)" << std::endl;
	print(aggregated_values);

	std::move();
	std::forward()

		return 0;
}
