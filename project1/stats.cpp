#include "stats.h"
#include <cassert>


namespace main_savitch_2C
{

/* constructor - setting initial values for private variables  */
statistician::statistician()
{
  count = 0;
  total = 0.0;
  smallest = 0.0;
  largest = 0.0;
}


void statistician::next(double r)
{
  // double a, b, recent;
  if (count >= 0)
  {
    /*count = 1;
    total = r;*/
    /*a = smallest;
    b = largest;*/
    //return;

    count = count + 1;
    total = total + r;

/*     keeping track of max and min      */
    if (r < smallest)
    {
      smallest = r;
    }
    if (r > largest)
    {
      largest = r;
    }
  }
}


void statistician::reset()
{
  count = 0;
  total = 0;
}

/*
void statistician::setcount(int s_count)
{
  s_count = count;
}

void statistician::settotal(double s_total)
{
  s_total = total;
}

void statistician::setsmallest(double s_smallest)
{
  s_smallest = smallest;
}

void statistician::setlargest(double s_largest)
{
  s_largest = largest;
}
*/

int statistician::length() const
{
  return count;
}

double statistician::sum() const
{
  return total;
}

double statistician::mean() const
{
  double mean;

/*   make sure user actually inputed a value; dont want to divide by zero  */

  assert (count > 0);
  mean = total/count;
  return mean;
}

double statistician::minimum() const
{
  return smallest;
}

double statistician::maximum() const
{
  return largest;
}

bool operator ==(const statistician& s1, const statistician& s2)
{
  return (s1.length() == s2.length() && s1.mean() == s2.mean() && s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum() && s1.sum() == s2.sum());
}

statistician operator +(const statistician& s1, const statistician& s2)
{
  statistician summation;
  summation.next(s1.length() + s2.length());
  return summation;
}


statistician operator *(double scale, const statistician& s)
{
  statistician product;
  product.next(s.length() * scale);
  return product;
}
}
