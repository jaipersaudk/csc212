#include "sequence2.h"
#include <cassert>

namespace main_savitch_4
{
  const sequence::size_type sequence::DEFAULT_CAPACITY;

  // CONSTRUCTOR, COPY CONSTRUCTOR, DESTRUCTOR

  sequence::sequence(size_type initial_capacity)
  {
    data = new value_type[initial_capacity];
    capacity = initial_capacity;
    used = 0;
    current_index = 0;
    if (initial_capacity < 1)
      capacity = 1;
  }

  sequence::sequence(const sequence& source)
  {
    used = source.used;
    current_index = source.current_index;
    capacity = source.capacity;
    data = new value_type[source.capacity];
    for (size_type i = 0; i < used; ++i)
    {
      data[i] = source.data[i];
    }
  }

  sequence::~sequence()
  {
    delete [] data;
    data = NULL;
  }

  // MODIFICATION MEMBER FUNCTIONS

  void sequence::resize(size_type new_capacity)
  {
      value_type* temp_arr; //create a new array

      if ((new_capacity = capacity))
        return; //check if the new allocated memory is the same size as the old one

      if (new_capacity < used)
        capacity = used;

      if (new_capacity < 1)
        new_capacity = 1;

      temp_arr = new value_type[capacity];
      for (size_type i = 0; i < used; ++i)
      {
        temp_arr[i] = data[i];
      }

      delete [] data;
      data = temp_arr;
  }

  void sequence::start()
  {
    current_index = 0;
  }

  void sequence::advance()
  {
    assert(is_item());
    current_index = current_index + 1;
  }

  void sequence::insert(const value_type& entry)
  {
    // check if the array is full
    if (used == capacity)
      resize(size_type(capacity*2)+1);

    if(!is_item())
    {
      current_index = 0;
      for (size_type i = used + 1; i > current_index; --i)
      {
        data[i] = data[i-1];
      }
      data[current_index] = entry;
      ++used;
    }

    else
    {
      for (size_type i = used + 1; i > current_index; --i)
      {
        data[i] = data[i-1];
      }
      data[current_index] = entry;
      ++used;
    }
  }

  void sequence::attach(const value_type& entry)
  {
    if(used == capacity)
      resize(size_type(capacity*2)+1);

    if (!is_item())
    {
      data[current_index] = entry;
      ++used;
    }
    else
    {
      ++current_index;
      for (size_type i = used + 1; i > current_index; --i)
      {
        data[i] = data[i-1];
      }
      data[current_index] = entry;
      ++used;
    }
  }

  void sequence::remove_current( )
  {
    assert(is_item());
    for (size_t i = current_index; i < used - 1; ++i)
    {
      data[i] = data[i+1];
    }
    --used;
  }

  void sequence::operator =(const sequence& source)
  {
    value_type* new_data;
    if (this == &source)
      return;

    if (capacity != source.capacity)
    {
      new_data = new value_type[source.capacity];
      delete [] data;
      data = new_data;
      capacity = source.capacity;
    }

    used = source.used;
  }


  // CONSTANT MEMBER FUNCTIONS
  sequence::size_type sequence::size() const
  {
    return used;
  }

  bool sequence::is_item() const
  {
    return (current_index < used);
  }

  sequence::value_type sequence::current() const
  {
    assert(is_item());
    return current_index;
  }

}
