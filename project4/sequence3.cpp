#include "sequence3.h"
#include <cassert> // For Assert
#include <cstdlib> // For NULL
#include "node1.h"
#include <iostream>
using namespace std;

/* LIST_PIECE FUNCTION IS DECLARED IN NODE1.H AND IMPLEMENTED IN NODE1.CXX */

namespace main_savitch_5
{
  // CONSTRUCTOR, COPY CONSTRUCTOR, DESTRUCTOR
  sequence::sequence()
  {
    // initialize pointers to NULL and empty list
    many_nodes = 0;
    head_ptr = NULL;
    tail_ptr = NULL;
    precursor = NULL;
    cursor = NULL;
  }

  sequence::sequence(const sequence& source)
  {
    // empty list
    if (source.cursor == NULL)
    {
      list_copy(source.head_ptr, head_ptr, tail_ptr);
      precursor = NULL;
      cursor = NULL;
    }

    // cursor is at the first item in the list
    else if (source.cursor == source.head_ptr)
    {
      list_copy(source.head_ptr, head_ptr, tail_ptr);
      precursor = NULL;
      cursor = head_ptr;
    }

    //cursor is located at another spot other than the head pointer
    else
    {
      // Piece 1: copying from the first item up to, but no including the cursor
      list_piece(source.head_ptr, source.cursor, head_ptr, precursor);

      // Piece 2: copying from the cursor untl the end of the list
      list_piece(source.cursor, NULL, cursor, tail_ptr);

      // putting the two pieces together
      precursor->set_link(cursor);
    }

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
    precursor = NULL;
    cursor = head_ptr;
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
    // cursor is an item
    if (is_item())
    {
      // cursor at the first item
      if (precursor == NULL)
      {
        list_head_insert(head_ptr, entry);
        cursor = head_ptr;
        precursor = NULL;
      }

      // insert after precursor
      else
      {
        list_insert(precursor, entry);
        cursor = precursor->link();
      }
    }

    // cursor isnt an item, insert item at the beginning of list
    if (!is_item())
    {
      list_head_insert(head_ptr, entry);
      precursor = NULL;
      cursor = head_ptr;
    }

    many_nodes++;
  }

  void sequence::attach(const value_type& entry)
  {
    // cursor is an item
    if(is_item())
    {
      precursor = cursor;
      list_insert(cursor, entry);
      cursor = cursor->link();
    }

    // cursor isnt an item
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
    // checking self-assignment
    if (this == &source)
      return;

    if (this != &source)
    {
      list_copy(source.head_ptr, head_ptr, tail_ptr);
      if (source.precursor == NULL)
      {
        // empty list
        if (source.cursor == NULL)
        {
          precursor = NULL;
          cursor = NULL;
        }

        else
        {
          precursor = NULL;
          cursor = head_ptr;
        }
      }

      else
      {
        // create temporary pointers
        node* temp_ptr = head_ptr;
        node* source_ptr = source.head_ptr;
        while (source_ptr != source.precursor)
        {
          source_ptr = source_ptr->link();
          temp_ptr = temp_ptr->link();
        }

        cursor = temp_ptr->link();
        precursor = temp_ptr;
      }
    }

    many_nodes = source.many_nodes;
  }

  void sequence::remove_current( )
  {
    // Precondition
    assert(is_item());

    // if the cursor is at head pointer
    if (cursor == head_ptr)
    {
      // and there is only one item in the list
      if (many_nodes == 1)
      {
        list_head_remove(head_ptr);
        precursor = NULL;
        cursor = NULL;
      }

      // else head pointer points to next item and old head pointer is removed
      else
      {
        node* temp = head_ptr;
        head_ptr = head_ptr->link();
        delete (temp);
        cursor = head_ptr;
        precursor = NULL;
      }
    }

    // move cursor to next item and remove precursor
    else
    {
      cursor = cursor->link();
      list_remove(precursor);
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
