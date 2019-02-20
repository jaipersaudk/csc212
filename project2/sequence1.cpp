#include "sequence1.h"
#include <cassert>

namespace main_savitch_3
{
  const sequence::size_type sequence::CAPACITY;

  sequence::sequence()
  {
    used = 0;
    current_index = 0;
  }


  void sequence::start()
  {
    current_index = 0;
  }


  void sequence::advance()
  {
    //assert(is_item());
    ++current_index;
  }

/* MINE - TWO DIFFERENT ONES
  void sequence::insert(const value_type& entry)
  {

    assert(size() < CAPACITY);
    data[used] = entry;
    ++used;



    assert(size() < CAPACITY);
    if (!is_item()) //check to see if there is a current item
      current_index = used;

    for (size_t i = used; i > current_index; i--)
    {
      data[i] = data[i-1];
      data[current_index] = entry;
      used++;
    }

    data[current_index] = entry;
    ++current_index;
    ++used;

  }
*/
  void sequence::insert(const value_type& entry)
  {
    assert(size() < CAPACITY);

    for (int i = used; i > current_index; i--)
    {
      data[i] = data[i-1];
      data[current_index] = entry;
      used++;
    }

  }



  void sequence::attach(const value_type& entry)
  {

    size_type index;
    assert( size() < CAPACITY);
    if ( !is_item() )
    {
      current_index = used-1;
    }
    for (index = used; index > current_index + 1; --index)
    {
      data[index] = data[index-1];
    }
    data[current_index+1] = entry;
    ++current_index;
    ++used;
  }


/* NOT MINE
  void sequence::attach(const value_type& entry)
  {
    assert(size() < CAPACITY);
    for (int i = used; i > current_index; i--)
    {
      data[i] = data[i+1];
      data[current_index] = entry;
      used++;
    }
  }
*/

  void sequence::remove_current()
  {
    //assert(is_item());
    size_type index;
    for (index = current_index + 1; index < used; ++index)
    {
      data[index-1] = data[index];
    }
    --used;
  }


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
    //assert(is_item());
    return data[current_index];
  }
}
