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
    //current_index = 0;
  }

  sequence::sequence(const sequence& source)
  {
    data = new value_type[source.capacity];
    capacity = source.capacity;
    used = source.used;
    //copy(source.data, source.data + used, data);
  }

  sequence::~sequence()
  {
    delete [] data;
  }

  // MODIFICATION MEMBER FUNCTIONS

  void sequence::resize(size_type new_capacity)
  {
      value_type* big_array; //create a new array

      if(new_capacity = capacity)
        return; //check if the new allocated memory is the same size as the old one

      if (new_capacity < used)
        new_capacity = used;

      big_array = new value_type[new_capacity];
      // copy(data, data + used, big_array);
      delete [] data;
      data = big_array;
      capacity = new_capacity;
  }

  void sequence::start()
  {
    current_index = 0;
  }

  void sequence::advance()
  {
    assert(is_item());
    ++current_index;
  }

  void sequence::insert(const value_type& entry)
  {

  }

  void sequence::attach(const value_type& entry)
  {

  }

  void sequence::remove_current( )
  {

  }

  void sequence::operator =(const sequence& source)
  {

  }


  // CONSTANT MEMBER FUNCTIONS
  sequence::size_type sequence::size() const
  {
    return used;
  }

  bool sequence::is_item()
  {
    return (current_index < used);
  }

  sequence::value_type sequence::current() const
  {
    return current_index;
  }


}
