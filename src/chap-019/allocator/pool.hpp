#ifndef POOL_HPP
#define POOL_HPP

//#define DEBUG 1

#include <algorithm>

//#include <pair>
//TODO: Implement memory leaks detection
class Pool
{
public:
  const static int HASH_EXCEEDED_LIMITS = -1;
  const static size_t BUCKETS_SIZE = 21;
private:
  const static ptrdiff_t LINK_OFFSET = 2;
  struct ILink
  {
    ILink *next;
    ILink *previous;
  };

  ILink* _buckets[BUCKETS_SIZE];
  ILink* _used_buckets[BUCKETS_SIZE];
  


public:
  size_t get_bucket_size(size_t item_size);
  int get_hash(size_t size);
  int get_bucket_index(size_t required_size);
  size_t get_bucket_size_by_index(int bucket_index);

public:
  Pool();
  ~Pool();
  
  void* allocate(size_t size);
  void deallocate(void* ptr, size_t size);
};

Pool::Pool()
{
#if DEBUG
  std::cout << "Pool::Pool::initialize_buckets" << std::endl;
#endif
  
  for(int idx = 0; idx < BUCKETS_SIZE; ++idx)
    _buckets[idx] = nullptr;
}

Pool::~Pool()
{
#if DEBUG
  std::cout << "Pool::~Pool::delete_buckets" << std::endl;
#endif
  for(int idx = 0; idx < BUCKETS_SIZE; ++idx)
  {
#if DEBUG    
    std::cout << "Pool::~Pool::delete_buckets[index=" << idx << "]" << std::endl;
#endif
    ILink *head = _buckets[idx];
    while(head != nullptr)
    {
      ILink *current = head;
      head = current->next;
#if DEBUG      
      std::cout << "Pool::~Pool::delete_buckets[index=" << idx << ", ptr=" << current << "]" << std::endl;
#endif
      size_t bucket_size = get_bucket_size_by_index(idx);
      char *item = static_cast<char *>(static_cast<void *>(current));

      delete[] item;
    }
    _buckets[idx] = nullptr;
  }
}


size_t Pool::get_bucket_size(size_t item_size)
{
  //size_t actual_size = std::max(item_size, sizeof(ILink));
  size_t actual_size = item_size + sizeof(ILink);
  //  std::cout << actual_size << std::endl;
  
  int result = 1;
  
  while(result < actual_size)
    result <<= 1;

  return result;
}

int Pool::get_hash(size_t size)
{
  int result = -1;
  
  while(size)
  {
    size >>= 1;
    result++;
  }

  return result;
}

int Pool::get_bucket_index(size_t required_size)
{
  // Calculate mem amount (req + size of link)
  //  size_t total_item_size = required_size + sizeof(ILink);
  // Calculate nearest to 2^n amount
  size_t bucket_size = get_bucket_size(required_size);
  //std::cout << "bs=" << bucket_size << std::endl;
  int bucket_index = get_hash(bucket_size);
  //std::cout << "bi=" << bucket_index << std::endl;
  //  std::cout << "sizeof(ILink)" << sizeof(ILink) << std::endl;

  if(bucket_index < 0 || bucket_index >= BUCKETS_SIZE)
    throw std::out_of_range("Can not find appropriate bucket. Size is out of range.");

  return bucket_index;
}

size_t Pool::get_bucket_size_by_index(int bucket_index)
{
  int result = 1;
  
  while(bucket_index--)
  {
    result <<= 1;
  }

  return result;
}

void* Pool::allocate(size_t size)
{
  int bucket_index = get_bucket_index(size);
  ILink* bucket_head = _buckets[bucket_index];
  
  if(bucket_head != nullptr)
  {
    _buckets[bucket_index] = bucket_head->next;
#if DEBUG
    std::cout << "Pool::allocate::item reused[ptr=" << ((void *)bucket_head) << ", index=" << bucket_index << "]" << std::endl;
#endif

    return static_cast<void *>(bucket_head) + LINK_OFFSET;
  }
  else
  {
    size_t bucket_size = get_bucket_size(size);
    char *item = new char[bucket_size];
#if DEBUG
    std::cout << "Pool::allocate::new item created[ptr=" << ((void *)item) << ", index=" << bucket_index << ", size=" << bucket_size << "]" << std::endl;
#endif
    return static_cast<void *>(item) + LINK_OFFSET;
  }
}

void Pool::deallocate(void* ptr, size_t size)
{
  //Shift two pointers(prev,next) bacl
  void *link_ptr = ptr  - LINK_OFFSET;
  
  ILink *link = static_cast<ILink *>(link_ptr);
  int bucket_index = get_bucket_index(size);
  if(_buckets[bucket_index] == nullptr)
  {
#if DEBUG
    std::cout << "Pool::deallocate::add_head[ptr=" << ((void *)ptr) << ", link_ptr=" << ((void *)link_ptr) << ", size=" << size << ", bucket_size=" << get_bucket_size(size) << ", bucket_index=" << bucket_index << "]" << std::endl;
#endif
    link->next = nullptr;
    _buckets[bucket_index] = link;
  }
  else
  {
#if DEBUG
    std::cout << "Pool::deallocate::update_head[ptr=" << ((void *)ptr) << ", link_ptr=" << ((void *)link_ptr) << ", size=" << size << ", bucket_size=" << get_bucket_size(size) << ", bucket_index=" << bucket_index << "]" << std::endl;
#endif
    link->next = _buckets[bucket_index];
    _buckets[bucket_index] = link;
  }
}

#endif
