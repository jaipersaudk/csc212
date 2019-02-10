#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
  double r, s, t, u;
  cin >> r;
  s = r;
  while (cin >> t)
  {
    if (abs(t) < r)
      s = abs(t);
  }
  cout << s << endl;
  return 0;
}