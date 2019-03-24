#include "sequence3.h"
#include <cassert> // For Assert
#include <cstdlib> // For NULL
#include "node1.h"
#include <iostream>
using namespace std;

namespace main_savitch_5
{
  // CONSTRUCTOR, COPY CONSTRUCTOR, DESTRUCTOR
  sequence::sequence()
  {
    many_nodes = 0;
    head_ptr = NULL;
    tail_ptr = NULL;
    precursor = NULL;
    cursor = NULL;
  }

  sequence::sequence(const sequence& source)
  {
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    list_copy(source.cursor, cursor, precursor);
    many_nodes = source.many_nodes;
  }

  sequence::~sequence()
  {
    //remove everything and return to heap
    list_clear(head_ptr);
    many_nodes = 0; // not necessary but it makes it known that everything is being removed
  }

  // MODIFICATION MEMBER FUNCTIONS
  void sequence::start( )
  {
    // move cursor back to beginning
    cursor = head_ptr;
    precursor = NULL;
  }

  void sequence::advance( )
  {
    // Precondition
    assert(is_item());

    // move forward
    precursor = cursor;
    cursor = cursor->link();
  }

  void sequence::insert(const value_type& entry)
  {
    if (is_item())
    {
      // empty list
      if (precursor == NULL)
      {
        list_head_insert(head_ptr, entry);
        cursor = head_ptr;
        precursor = NULL;
      }

      else
      {
        list_insert(precursor, entry);
        cursor = precursor->link();
      }
    }

    if (!is_item())
    {
      list_head_insert(head_ptr, entry);
      cursor = head_ptr;
      precursor = NULL;
    }

    many_nodes++;
  }

  void sequence::attach(const value_type& entry)
  {
    if(is_item())
    {
      precursor = cursor;
      list_insert(cursor, entry);
      cursor = cursor->link();
    }

    if (!is_item())
    {
      if (precursor == NULL)
      {
        list_head_insert(head_ptr, entry);
        cursor = head_ptr;
        precursor = NULL;
      }

      else
      {
        cursor = list_locate(head_ptr, list_length(head_ptr));
        list_insert(cursor, entry);
        cursor = precursor->link();
      }
    }

    many_nodes++;
  }

  void sequence::operator =(const sequence& source)
  {
    // checking for self-assignment
    if (this == &source)
    {
      return;
    }

    else
    {
      list_clear(head_ptr);
      list_copy(source.head_ptr, head_ptr, tail_ptr);
      if (source.precursor == NULL)
      {
        if (source.cursor == NULL)
        {
          cursor = NULL;
          precursor = NULL;
        }
        else
        {
          cursor = head_ptr;
          precursor = NULL;
        }
      }
      else
      {
        node *temp_ptr = head_ptr;
        node *source_ptr = source.head_ptr;
        while (source_ptr != source.precursor)
        {
          source_ptr = source_ptr->link();
          temp_ptr = temp_ptr->link();
        }
        cursor = temp_ptr->link();
        precursor = temp_ptr;
      }
      many_nodes = source.many_nodes;
    }
  }


  void sequence::remove_current( )
  {
    // Precondition - make sure cursor isnt outside the list
    assert(is_item());

    // if the cursor is pointing to the first node, then remove the first node
    if (cursor == head_ptr)
    {
      cursor = cursor->link();
      list_head_remove(head_ptr);
    }

    else
    {
      cursor = cursor->link();
      list_remove(head_ptr);
    }

    --many_nodes;
  }


  // CONSTANT MEMBER FUNCTIONS
  sequence::size_type sequence::size() const
  {
    return many_nodes;
  }

  bool sequence::is_item( ) const
  {
    return ((cursor != NULL) && (size() > 0));
  }

  sequence::value_type sequence::current() const
  {
    assert(is_item());
    return cursor->data();
  }

}
