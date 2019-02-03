#ifndef stats_h
#define stats_h
#include <iostream> //is this necessary?

namespace main_savitch_2C
{
  class statistician
  {
    public:
/*     constructor  */
    statistician();

/*   MEMBER functions  */
  void next(double r);

  void reset();

/*     accessing the private variables  */
    void getCount(int g_count);

    void getTotal(double g_total);

    void getSmallest(double g_smallest);

    void getLargest(double g_largest);

/*   CONSTANT member functions  */

  int length() const {
    return count;
  }

  double sum() const {
    return total;
  }


  double mean() const;

  double minimum() const;

  double maximum() const;

/*   NON-MEMBER functions  */
  friend statistician operator +
  (const statistician& s1, const statistician& s2);

  friend statistician operator *(double scale, const statistician& s);

  private:
  int count; //How many #'s in the sequence
  double total; //sum of all #'s in the sequence
  double smallest; //smallest # in the sequence
  double largest; //largest # in the sequence

};

/* NON-MEMBER functions  */
bool operator ==(const statistician& s1, const statistician& s2);

#endif