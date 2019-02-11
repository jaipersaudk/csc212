#include "stats.h"
#include <cassert>
#include <cmath>


namespace main_savitch_2C
{

/* constructor - setting initial values for some private variables  */
statistician::statistician()
{
  count = 0;
  total = 0.0;
}


void statistician::next(double r)
{
  double temp_min, temp_max, temp_absmin, temp_absmax;
  if (count >= 0)
  {
    count = count + 1;
    total = total + r;
    recent = r;

/* keeping track of max and min  */
    if (count == 1) {
      smallest = r;
      largest = r;
      abs_min = abs(r);
      abs_max = abs(r);
    }

    else {
      temp_min = r;
      temp_max = r;

      if (temp_min < smallest)
        smallest = temp_min;

      if (temp_max > largest)
        largest = temp_max;

/* keeping track of absolute max and min  */
      temp_absmin = abs(r);
      if (temp_absmin < abs_min)
        abs_min = temp_absmin;

      temp_absmax = abs(r);
      if (temp_absmax > abs_max)
        abs_max = temp_absmax;
    }
  }
}

void statistician::reset()
{
  count = 0;
  total = 0;
}


int statistician::length() const
{
  return count;
}

double statistician::sum() const
{
  return total;
}

double statistician::last() const
{
  assert (count > 0);
  return recent;
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
  assert (count > 0);
  return smallest;
}

double statistician::maximum() const
{
  assert (count > 0);
  return largest;
}


double statistician::abs_minimum() const
{
  assert (count > 0);
  return abs_min;
}


double statistician::abs_maximum() const
{
  assert (count > 0);
  return abs_max;
}

bool operator ==(const statistician& s1, const statistician& s2)
{
  return (s1.length() == s2.length() && s1.mean() == s2.mean() && s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum() && s1.sum() == s2.sum());
}

statistician operator +(const statistician& s1, const statistician& s2)
{
  statistician summation;
  summation.next(s1.sum() + s2.sum());
  return summation;
}

/* If the scalar was inserted first ( EX: w = 2*u)  */
statistician operator *(double scale, const statistician& s)
{
  statistician product;
  product.next(s.sum() * scale);
  return product;
}

/* If the scalar was inserted second ( EX: w = u*2)  */
statistician operator *(const statistician& s, double scale)
{
  statistician product;
  product.next(s.sum() * scale);
  return product;
}
}
