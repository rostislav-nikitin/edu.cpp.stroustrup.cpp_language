#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include "pool.hpp"

template<class T>
class Allocator;

template<>
class Allocator<void>
{
  
public:
  typedef void value_type;
  typedef size_t size_type;

  typedef ptrdiff_t difference_type;
  
  typedef void *pointer;
  typedef void const *const_pointer;
};

template<class T>
class Allocator
{
  static Pool _pool;
public:
  typedef T value_type;
  typedef size_t size_type;

  typedef ptrdiff_t difference_type;
  
  typedef T *pointer;
  typedef T const *const_pointer;

  typedef T &reference;
  typedef T const &const_reference;

  pointer address(reference ref) const;
  const_pointer address(const_reference ref) const;

  Allocator();
  
  ~Allocator();

  pointer allocate(size_type items_to_allocate, Allocator<void>::const_pointer opt = nullptr);
  void deallocate(pointer starts_at, size_type items_do_deallocate);

  void construct(pointer starts_at, const_reference value);
  void deconstruct(pointer starts_at);
};

template<class T>
Pool Allocator<T>::_pool;


template<class T>
Allocator<T>::Allocator()
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<class T>
Allocator<T>::~Allocator()
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<class T>
typename Allocator<T>::pointer Allocator<T>::address(reference ref) const
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
    
  return &ref;
}

template<class T>
typename Allocator<T>::const_pointer Allocator<T>::address(const_reference ref) const
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  
  return &ref;
}

template<class T>
typename Allocator<T>::pointer Allocator<T>::allocate(size_type items_to_allocate, Allocator<void>::const_pointer opt)
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::cout << "NOT! Stub" << std::endl;

  pointer result = static_cast<pointer>(_pool.allocate(items_to_allocate * sizeof(value_type)));
  
  return result;
}

template<class T>
void Allocator<T>::deallocate(pointer starts_at, size_type items_to_deallocate)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << "NOT! Stub" << std::endl;
    //delete starts_at;

    _pool.deallocate(starts_at, items_to_deallocate * sizeof(value_type));
}

template<class T>
void Allocator<T>::construct(pointer starts_at, const_reference value)
{
  new (starts_at)T(value);
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<class T>
void Allocator<T>::deconstruct(pointer starts_at)
{
  starts_at->~T();
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}


#endif
