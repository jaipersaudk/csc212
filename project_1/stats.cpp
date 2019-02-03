#include <iostream>
#include <cassert>
#include "stats.h"
using namespace std;


/* constructor - setting initial values for private variables  */
statistician::statistician()
{
  count = 0;
  total = 0.0;
  smallest = 0.0;
  largest = 0.0;
}

void statistician::next(double r) {
  if (count<=0)
  {
    count = 1;
    total = r;
    minimum = r;
    maximum = r;
    return;

    count = count +1;
    total += r;
/*     keep track of max and min  */
    if (r < minimum)
    {
      minimum = r;
    }
    if (r > maximum)
    {
      maximum = r;
    }
  }
}


void statistician::reset()
{
  count = 0;
  total = 0;
}

void statistician::getCount(int g_count)
{
  g_count = count;
}

void statistician::getTotal(double g_total)
{
  g_total = total;
}

void statistician::getSmallest(double g_smallest)
{
  g_smallest = smallest;
}

void statistician::getLargest(double g_largest)
{
  g_largest = largest;
}


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

double statistician:: maximum() const
{
  return largest;
}



