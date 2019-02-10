#ifndef stats_h
#define stats_h
#include <iostream>

namespace main_savitch_2C
{
  class statistician
  {
    public:
/*     constructor  */
    statistician();
/*     Postcondition: Object is initialized and will accept numbers from user  */

/*   MEMBER functions  */
  void next(double r);
/*     r is the next number in the sequence of numbers  */

  void reset();
/*     Postcondition: all numbers are cleared and is ready to accept new numbers  */




/*     Functions to access the private variables  ---  g_something means get something     ex: g_count is get count  */
/*     void setcount(int s_count);
 *
 *     void settotal(double s_total);
 *
 *     void setsmallest(double s_smallest);
 *
 *     void setlargest(double s_largest);
 *
 *
 */


/*   CONSTANT member functions  */

  int length() const;
/*   Postcondition: Returns the length of the sequence (# of times next(r) has been activated) (COUNT) */


  double sum() const;
/*   Postcondition: returns the sum of all numbers in the sequence  (TOTAL)*/


  double last() const;

  double mean() const;
/*   Precondition: length() > 0  */
/*   Postcondition: returns the value of the mean of the sequence  */

  double minimum() const;
/*   Precondition: length() > 0  */
/*   Postcondition: returns the smallest number in sequence  */

  double maximum() const;
/*   Precondition: length() > 0  */
/*   Postcondition: returns the largest number in the sequence  */

  double abs_maximum() const;

  double abs_minimum() const;



/*   Friend functions  */
  friend statistician operator +(const statistician& s1, const statistician& s2);
/*   Postcondition: The statistician that is returned contains all the numbers of the sequences of s1 and s2  */

  friend statistician operator *(double scale, const statistician& s);
/*   Postcondition: The statistician that is returned contains the same numbers that s does, but each number has been multiplied by the scale numbers  */




  private:
  int count; //How many #'s in the sequence
  double total; //sum of all #'s in the sequence
  double smallest; //smallest # in the sequence
  double largest; //largest # in the sequence
  double abs_min;
  double abs_max;
  double recent;

};

/* NON-MEMBER functions  */
bool operator ==(const statistician& s1, const statistician& s2);
/*   Postcondition: The return value is true if s1 and s2 have the zero length. Also, if the length is greater than zero, then s1 and s2 must have the same length, mean, minimum, maximum, and sum  */
}

#endif