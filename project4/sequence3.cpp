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
    list_copy(source.head_ptr, head_ptr, tail_ptr); // source.head_ptr is the head pointer of the original list; head_ptr is the new head pointer
    list_copy(source.cursor, cursor, precursor);
    many_nodes = source.many_nodes;
  }


  /*sequence::sequence(const sequence& source) // BEST ONE
  {
    // if cursor is NULL
    if (source.cursor == NULL)
    {
      list_copy(source.head_ptr, head_ptr, tail_ptr);
      precursor = NULL;
      cursor = NULL;
    }

    // if cursor at the first item of the list
    else if (source.cursor == source.head_ptr)
    {
      list_copy(source.head_ptr, head_ptr, tail_ptr);
      precursor = NULL;
      cursor = head_ptr;
    }

    many_nodes = source.many_nodes;
  }
  */

  sequence::~sequence()
  {
    //remove everything and return to heap
    list_clear(head_ptr);
    many_nodes = 0; // not necessary but it makes it known that everything is being removed
  }

  // MODIFICATION MEMBER FUNCTIONS
  void sequence::start( )
  {
    // if there are no items
    if ((head_ptr == NULL) && (tail_ptr == NULL))
      return;

    // if there is at least one item
    cursor = head_ptr;
    precursor = NULL;
  }

  void sequence::advance( )
  {
    // Precondition
    assert(is_item());

    precursor = cursor;
    cursor = cursor->link();
  }


  /*void sequence::advance()
  {
    // Precondition
    assert(is_item());

    // if cursor is at the last item of the list (NULL)
    if (cursor == NULL)
    {
      precursor = NULL;
    }

    // otherwise
    precursor = cursor;
    cursor = cursor->link();
  }
  */

  /*void sequence::insert(const value_type& entry)
  {
    // if the list is empty
    if (head_ptr == NULL)
    {
      list_head_insert(head_ptr, entry);
      cursor = head_ptr;
      precursor = NULL;
      tail_ptr = head_ptr;
      ++many_nodes;
    }

    // if the cursor is outside the sequence
    else if (cursor == NULL || precursor == NULL)
    {
      list_head_insert(head_ptr, entry);
      cursor = head_ptr;
      precursor = NULL;
      ++many_nodes;
    }

    // inserts the item before cursor
    else
    {
      list_insert(precursor, entry);
      cursor = precursor->link();
      ++many_nodes;
    }
  }
  */ // best one

  /*void sequence::insert(const value_type& entry)
  {
    if ((precursor == NULL) || (!is_item()))
    {
      list_head_insert(head_ptr, entry);
      precursor = NULL;
      cursor = head_ptr;

      if (many_nodes == 0)
      {
        tail_ptr = head_ptr;
      }
    }

    else
    {
      list_insert(precursor, entry);
      cursor = precursor->link();
    }

    ++many_nodes;
  }
  */

  void sequence::insert(const value_type& entry)
  {
    if (is_item())
    {
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

  /*void sequence::attach(const value_type& entry) //BEST ONE
  {
    // if the list is empty
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
  */


  /*void sequence::attach(const value_type& entry)
  {
    if (is_item())
    {
      if (cursor == tail_ptr)
      {
        precursor = cursor;
        list_insert(precursor, entry);
        cursor = cursor->link();
        tail_ptr = tail_ptr->link();
      }

      else
      {
        precursor = cursor;
        list_insert(precursor, entry);
        cursor = cursor->link();
      }
    }

    if (!is_item())
    {
      if ((head_ptr == NULL) && (tail_ptr == NULL))
      {
        list_head_insert(head_ptr, entry);
        precursor = NULL;
        cursor = head_ptr;
        tail_ptr = head_ptr;
      }

      else
      {
        precursor = list_locate (head_ptr, list_length(head_ptr));
        list_insert(precursor, entry);
        cursor = precursor->link();
        tail_ptr = tail_ptr->link();
      }
    }

    ++many_nodes;
  }
  */

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

  /*void sequence::operator =(const sequence& source) // BEST ONE
  {
    node* tail_ptr;

    // Check Self-Assignment
    if (this == &source)
    {
      return;
    }

    // bag already exists and it needs to be changed to be the same as some other bag
    // remove everything from bag and return to heap
    if (this != &source)
    {
      list_clear(head_ptr);
      // head_ptr = NULL;
      // tail_ptr = NULL;
      // cursor = NULL;
      // precursor = NULL;
      many_nodes = 0;

      // copy everything
      many_nodes = source.many_nodes;
      cursor = source.cursor;
      precursor = source.precursor;
      list_copy(source.head_ptr, head_ptr, tail_ptr);
    }
  }
  */

  void sequence::operator =(const sequence& source)
  {
    if (this == &source)
      return;

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
    // return list_length(head_ptr);
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
