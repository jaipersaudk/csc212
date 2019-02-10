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

  r.next(1);
  r.next(2);
  t.next(3);
  t.next(4);
  t.next(5);

  m = 2*t;
  a = r+t;
  cout << "Statistician r + s: " << a.sum() << endl;
  cout << "Statistician r * s: " << m.sum() << endl;

  s.next(18);
  s.next(-65);
  s.next(-57);
  s.next(23);
  s.next(32);

  u.next(18);
  u.next(-65);
  u.next(-57);
  u.next(23);
  u.next(32);

  equal = s == u;
  cout << "Are the sets of numbers equal: " << equal << endl;

  cout << "Sum: " << s.sum() << endl;
  cout << "Total: " << s.length() << endl;
  cout << "Mean " << s.mean() << endl;
  cout << "Smallest: " << s.minimum() << endl;
  cout << "Largest: " << s.maximum() << endl;
  cout << "Absolute Max: " << s.abs_maximum() << endl;
  cout << "Absolute Min: " << s.abs_minimum() << endl;
  cout << "Most Recent: " << s.last() << endl;

  return 0;
}
