#ifndef MAIN_SAVITCH_SEQUENCE_H
#define MAIN_SAVITCH_SEQUENCE_H
#include <cstdlib>

namespace main_savitch_3
{
  class sequence
  {
    public:

/*       TYPEDEF AND MEMBER FUNCTIONS  */
    typedef double value_type;
/*     Data type of the items in the sequence  */

    typedef std::size_t size_type;
/*     data type of any variable that keeps track of how many items are in a sequence  */

    static const size_type CAPACITY = 30;
/*     max number of items the sequence holds  */

/*     CONSTRUCTOR  */
    sequence();
/* Postcondition: Initialized as an empty sequence  */

/*     MODIFICATION MEMBER FUNCTIONS  */
    void start();
/*     Postcondition: the first item on the sequence becomes the current item (if empty, there is no current item)  */

    void advance();
/*     Precondition: is_item returns true
 *     Postcondition: If the current item was already the last item in the sequence, then there is no longer any current item. Otherwise, the new current item is the item immediately after the original current item    */

    void insert(const value_type& entry);
/*     Precondition: size() < CAPACITY
 *     Postcondition: A new copy of the entry has been inserted in the sequence before the current item. If there was no current item, then the new entry has been inserted at the front of the sequence. In either case, the newly inserted item is now the current item of the sequence   */

    void attach(const value_type& entry);
/*     Precondition: size() < CAPACITY
 *     Postcondition: A new copy of the entry has been inserted in the sequence after the current item. If there was no current item, then the new entry has been attached to the end of the sequence. In either case, the newly inserted item is now the current item of the sequence   */

    void remove_current();
/*     Precondition: is_item returns true
 *     Postcondition: The current item has been removed from the sequence, and the item after this is now the current item    */

/*     CONSTANT MEMBER FUNCTIONS  */
    size_type size() const;
/*     Postcondition: The return value is the number of items in the sequence  */

    bool is_item() const;
/*     Postcondition: A true return value indicates that there is a valid "current item" that may be retrieved by activating the current member function. A false return value indicates that there is no valid current item  */

    value_type current() const;
/*     Precondition: is_item() returns true;
 *     Postcondition: the item returned is the current item in the sequence   */


    private:
      value_type data[CAPACITY]; //an array to store items
      size_type used; //how much of the array is used
      size_type current_index;
  };
}

#endif