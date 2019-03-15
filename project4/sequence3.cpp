#include "sequence3.h"
#include <cassert>
#include <cstdlib>
#include <node1.h> //do i need this??
using namespace std;

namespace main_savitch_5
{
  // CONSTRUCTOR, COPY CONSTRUCTOR, DESTRUCTOR
  sequence::sequence()
  {
    head_ptr = NULL;
    tail_ptr = NULL;
    cursor = NULL;
    precursor = NULL;
    many_nodes = 0;
  }

  sequence::sequence(const sequence& source)
  {

  }

  sequence::~sequence()
  {
    //remove everything until head_ptr is NULL
    list_clear(head_ptr);
  }

  // MODIFICATION MEMBER FUNCTIONS
  void start( )
  {
    cursor = head_ptr;
    precursor = NULL;
  }

  void advance( )
  {
    // advance the cursor and the precursor
    assert(is_item());

    // is the assertment statement the same as this???
    if (cursor == tail_ptr)
    {
      cursor = NULL;
      precursor = NULL;
    }

    precursor = cursor;
    cursor = cursor->link();
  }

  void insert(const value_type& entry)
  {

  }

  void attach(const value_type& entry)
  {

  }

  void operator =(const sequence& source)
  {

  }

  void remove_current( )
  {

  }

  // CONSTANT MEMBER FUNCTIONS
  size_type size( ) const
  {
    // return list_length(head_ptr);
    return many_nodes;
  }

  bool is_item( ) const
  {
    return (cursor != NULL);
  }

  value_type current( ) const
  {
    assert(is_item());
    return cursor->data();
  }

}
