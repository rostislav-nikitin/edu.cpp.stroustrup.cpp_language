#ifndef SAFE_ITERATOR_HPP
#define SAFE_ITERATOR_HPP

#include <stdexcept>
#include <iterator>

template<class C>
class SafeIterator : public std::iterator<std::input_iterator_tag, typename C::value_type>
{
  //TODO: Check lh < rh && rh > lh
  template<class D>
  friend ptrdiff_t operator+(SafeIterator<D> const &, SafeIterator<D> const &);
  
  C& _container;
  
  typename C::iterator _current;
  typename C::iterator _begin;
  typename C::iterator _end;
  
  SafeIterator &seek_to_end();

  void validate() const;
  void validate_outdated() const;
  void validate_last() const;
  
  
public:
  SafeIterator(C &container, bool end = false);

  typename SafeIterator::value_type operator*();
  typename SafeIterator::value_type operator->();
  SafeIterator &operator++();
  SafeIterator operator++(int);
  bool operator==(SafeIterator const &other);
  bool operator!=(SafeIterator const &other); 
};

template<class C>
ptrdiff_t operator+(SafeIterator<C> const &lh, SafeIterator<C> const &rh)
{
  ptrdiff_t result = 0;
  
  for(SafeIterator<C> it_begin(lh); lh != rh; ++result, ++it_begin);
  
  return result;
}


template<class C>
SafeIterator<C>::SafeIterator(C &container, bool end) :
  _container(container), _current(container.begin()), _begin(container.begin()), _end(container.end())
{
  if(end)
    seek_to_end();
}


template<class C>
void SafeIterator<C>::validate() const
{
  validate_outdated();
  validate_last();
}

template<class C>
void SafeIterator<C>::validate_outdated() const
{
  bool valid = _begin == _container.begin() && _end == _container.end();

  if(!valid)
    throw std::runtime_error("Iterator outdated.");

}

template<class C>
 void SafeIterator<C>::validate_last() const
{
  if(_current == _container.end())
    throw std::out_of_range("Iterator at the end position.");
}

template<class C>
SafeIterator<C> &SafeIterator<C>::seek_to_end()
{
  while(_current != _container.end())
    ++_current;

  return *this;
}

template<class C>
typename SafeIterator<C>::value_type SafeIterator<C>::operator*()
{

  validate();
  
  return *_current;
}

template<class C>
typename SafeIterator<C>::value_type SafeIterator<C>::operator->()
{
  validate();
  
  return _current;
}

template<class C>
SafeIterator<C> &SafeIterator<C>::operator++()
{
  validate();
  
  ++_current;

  return *this;
}

template<class C>
SafeIterator<C> SafeIterator<C>::operator++(int)
{
  validate();
  
  SafeIterator temp = *this;
  
  ++_current;

  return temp;
}

template<class C>
bool SafeIterator<C>::operator==(SafeIterator const &other)
{
  return _current == other._current;
}

template<class C>
bool SafeIterator<C>::operator!=(SafeIterator const &other)
{
  return _current != other._current;
}

#endif
