#include <iostream>
#include <cmath>
#include "stats.h"
#include "stats.cpp"

using namespace std;
using namespace main_savitch_2C;

int main()
{
  statistician r;
  statistician s;
  statistician t;
  statistician u;
  statistician a;
  statistician m;
  bool equal;

/* Testing + and * operations  */
  r.next(1);
  r.next(2);
  t.next(3);
  t.next(4);
  t.next(5);

  m = 2*t;
  a = r+t;
  equal = r == t;
  cout << "Are r and t equal: " << equal << endl;
  cout << "Statistician r + s: " << a.sum() << endl;
  cout << "Statistician r * s: " << m.sum() << endl;

/* Testing Member Functions and == operator*/
  s.next(-55);
  s.next(46);
  s.next(-88);
  s.next(-85);
  s.next(79);

  u.next(79);
  u.next(-85);
  u.next(-88);
  u.next(46);
  u.next(-55);

  equal = s == u;
  cout << "Are s and u equal: " << equal << endl;

  cout << "Sum: " << s.sum() << endl;
  cout << "Total: " << s.length() << endl;
  cout << "Mean " << s.mean() << endl;
  cout << "Smallest: " << s.minimum() << endl;
  cout << "Largest: " << s.maximum() << endl;
  cout << "Absolute Min: " << s.abs_minimum() << endl;
  cout << "Absolute Max: " << s.abs_maximum() << endl;
  cout << "Most Recent: " << s.last() << endl;

  return 0;
}
