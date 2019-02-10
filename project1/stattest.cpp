#include <iostream>
#include "stats.h"
#include "stats.cpp"

using namespace std;
using namespace main_savitch_2C;

int main()
{
  statistician s;
  s.next(84);
  s.next(-86);
  s.next(-79);
  s.next(75);
  s.next(54);
  s.next(-78);
  s.next(-69);
  s.next(42);
  s.next(38);
  s.next(-64);
  s.next(-40);
  s.next(25);
  s.next(-4);
  s.next(-34);
  s.next(-100);

  cout << "Mean " << s.mean() << endl;
  cout << "Total: " << s.length() << endl;
  cout << "Sum: " << s.sum() << endl;
  cout << "Smallest: " << s.minimum() << endl;
  cout << "Maximum: " << s.maximum() << endl;
  cout << "Absolute Max: " << s.abs_maximum() << endl;
  cout << "Absolute Min: " << s.abs_minimum() << endl;
  cout << "Recent: " << s.last() << endl;

  return 0;
}
