#include <map>
#include <deque>
#include <cmath>
#include <numeric>

namespace Solatire
{
	namespace Engine
	{
		template<class T>
		class Target
		{
			std::map<int, std::deque<T>> _slots;
		public:
			typename std::map<int, std::deque<T>>::mapped_type &operator[](typename std::map<int, std::deque<T>>::key_type key);
			int get_max_count() const;
			int get_counts_sum() const;

			void reset();
		};

		template<class T>
		typename std::map<int, std::deque<T>>::mapped_type &Target<T>::operator[](typename std::map<int, std::deque<T>>::key_type key)
		{
			return _slots[key];
		}

		template<class T>
		int Target<T>::get_max_count() const
		{
			auto result = std::max_element(_slots.begin(), _slots.end(), [](std::pair<int, std::deque<T>> const &a, std::pair<int, std::deque<T>> const &b)
			{
				return a.second.size() < b.second.size();
			});

			return result->second.size();
		}

		template<class T>
		int Target<T>::get_counts_sum() const
		{
			int result = 0;
			std::for_each(_slots.begin(), _slots.end(), [&result](std::pair<int, std::deque<T>> const &a)
				{
					result += a.second.size();
				});

			return result;
		}

		template<class T>
		void Target<T>::reset()
		{
			_slots = std::map<int, std::deque<T>>();
		}
	}
}
