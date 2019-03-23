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
    head_ptr = NULL;
    tail_ptr = NULL;
    cursor = NULL;
    precursor = NULL;
    many_nodes = 0;
  }

  sequence::sequence(const sequence& source)
  {
    node* tail_ptr; // tail pointer for the new list
    list_copy(source.head_ptr, head_ptr, tail_ptr); // source.head_ptr is the head pointer of the original list; head_ptr is the new head pointer
    many_nodes = source.many_nodes; //keeping track of how many items are in the linked list
  }

  sequence::~sequence()
  {
    //remove everything until head_ptr is NULL
    list_clear(head_ptr);
    many_nodes = 0; // not necessary but it is known that everything is being removed
  }

  // MODIFICATION MEMBER FUNCTIONS
  void sequence::start( )
  {
    cursor = head_ptr;
    precursor = NULL;
  }

  /* void sequence::advance( )
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
  */

  void sequence::advance()
  {
    precursor = cursor;
    cursor = cursor->link();
  }

  void sequence::insert(const value_type& entry)
  {
    // if the list is empty
    if (head_ptr == NULL)
    {
      list_head_insert(head_ptr, entry);
      cursor = head_ptr;
      precursor = NULL;
      tail_ptr = head_ptr;
    }

    else if (!is_item())
    {
      //
      if (cursor == NULL || precursor == NULL)
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

    ++many_nodes;
  }

  /* void sequence::insert(const value_type& entry)
  {
    if (is_item())
    {
      if (cursor == NULL || precursor == NULL) //is this redundant??
      {
        list_head_insert(head_ptr, entry);
        cursor = head_ptr;
        precursor = NULL;
      }
      else
      {
        list_insert(precursor, entry);
        cursor = head_ptr;
      }
    }

    else
    {
      list_head_insert(head_ptr, entry);
      cursor = head_ptr;
      precursor = NULL;
    }
    ++many_nodes;
  }
  */

  void sequence::attach(const value_type& entry)
  {
    // if the list is empty or cursor is at the front of the list
    if (head_ptr == NULL)
    {
      list_head_insert(head_ptr, entry);
      cursor = head_ptr;
      precursor = NULL;
      tail_ptr = head_ptr;
      ++many_nodes;
    }

    // if cursor is at the tail_ptr or at the last element in the list (NULL)
    else if (cursor == NULL || cursor == tail_ptr)
    {
        list_insert(tail_ptr, entry);
        cursor = tail_ptr;
        precursor = tail_ptr;
        tail_ptr = tail_ptr->link();
        ++many_nodes;
    }

    else
    {
      list_insert(cursor, entry);
      precursor = cursor;
      cursor = cursor->link();
      ++many_nodes;
    }
  }

  /* void sequence::attach(const value_type& entry)
  {
    if(is_item())
    {
      precursor = cursor;
      list_insert(cursor, entry);
      cursor = cursor->link();
    }

    else
    {
      if (head_ptr == NULL)
      {
        list_head_insert(head_ptr, entry);
        cursor = head_ptr;
        precursor = NULL;
      }

      else
      {
        precursor = list_locate(head_ptr, list_length(head_ptr));
        list_insert(precursor, entry);
        cursor = precursor->link();
      }
    }
    ++many_nodes;
  }
  */

  void sequence::operator =(const sequence& source)
  {
    node* tail_ptr;

    // Checking for Self-Assignment
    if (this == &source)
      return;

    // bag already exists and it needs to be changed to be the same as some other bag
    // remove everything from bag and return to heap
    list_clear(head_ptr);
    many_nodes = 0;

    // copy everything
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    many_nodes = source.many_nodes;

  }

  void sequence::remove_current( )
  {
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
  sequence::size_type sequence::size( ) const
  {
    // return list_length(head_ptr);
    return many_nodes;
  }

  bool sequence::is_item( ) const
  {
    return (cursor != NULL);
  }

  sequence::value_type sequence::current( ) const
  {
    assert(is_item());
    return cursor->data();
  }

}
