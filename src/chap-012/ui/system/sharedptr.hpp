#include <iostream>

namespace UI
{
	namespace System
	{
		template<typename T>
		class SharedPtr
		{
		private:
			template<typename U>
			struct Holder
			{
				U* value;
				int refs;

				Holder(U *value);
				~Holder();
			};

			Holder<T> *_holder;

		public:
			SharedPtr(T *value);
			SharedPtr(SharedPtr<T> &ptr);
			SharedPtr(SharedPtr<T> const &ptr);
			~SharedPtr();

			T* get_value();

			T *operator->();
			T &operator*();
		};
	}
}

namespace UI
{
	namespace System
	{
		// Holder
		template<typename T>
		template<typename U>
		SharedPtr<T>::Holder<U>::Holder(U *value) : value(value), refs(1) { }

		template<typename T>
		template<typename U>
		SharedPtr<T>::Holder<U>::~Holder()
		{
			delete value;
		}
/*
		template<typename T>
		template<>
		SharedPtr<T>::Holder<char>::~Holder()
		{
			delete[] value;
		}
*/
		// Shared ptr
		template<typename T>
		SharedPtr<T>::SharedPtr(T *value) 
		{
			//std::cout << __PRETTY_FUNCTION__ << std::endl;
			_holder = new Holder<T>(value);
		}

		template<typename T>
		SharedPtr<T>::SharedPtr(SharedPtr<T> &ptr)
		{
			//std::cout << __PRETTY_FUNCTION__ << std::endl;
			_holder = ptr._holder;
			_holder->refs++;
		}

		template<typename T>
		SharedPtr<T>::SharedPtr(SharedPtr<T> const &ptr)
		{
			//std::cout << __PRETTY_FUNCTION__ << std::endl;
			_holder = ptr._holder;
			_holder->refs++;
		}

		template<typename T>
		SharedPtr<T>::~SharedPtr()
		{
			_holder->refs--;
			if(_holder->refs == 0)
			{
				delete _holder;
				//std::cout << "[DELETED]" << __PRETTY_FUNCTION__ << std::endl;
			}
			else
			{
				//std::cout <<  __PRETTY_FUNCTION__ << std::endl;
			}
		}

		template<typename T>
		T* SharedPtr<T>::get_value()
		{
			return _holder->value;
		}

		template<typename T>
		T* SharedPtr<T>::operator->()
		{
			return _holder->value;
		}

		template<typename T>
		T& SharedPtr<T>::operator*()
		{
			return *_holder->value;
		}
	}
}
