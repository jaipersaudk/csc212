// #include "rec_fun.h"
#include <iostream>
#include <cstring>

using namespace std;

class recursion
{
  public:
    void triangle(ostream& outs, unsigned int m, unsigned int n)
    {
      // base case
      if (m >= n)
        return;

      else
      {
        for (int i = m; i <= n; i++)
        {
          outs << "*";
        }
        outs << "\n";

        triangle(cout, m-1, n);
        for (int i = m; i <= n; i++)
        {
          outs << "*";
        }
        outs << "\n";
      }

    }

    void numbers(ostream& outs, const string& prefix, unsigned int levels)
    {

    }

    bool bears(unsigned int n)
    {
      // base case
      if (n == 42)
        return true;

      if (n < 42)
        return false;

      if (n != 42)
      {

        if ((n%5)==0)
        {
          n = n-42;
          return (bears(n));
        }

        if ((n%2)==0)
        {
          n = n - (n/2);
          return (bears(n));
        }

        if ( (n%3)==0 || ((n%4)==0) )
        {
          unsigned int i = n%10;
          unsigned int j = ((n%100)/10);
          n = n-(i*j);
          return (bears(n));
        }

      }

      return false;
    }

    void pattern(ostream& outs, unsigned int n, unsigned int i)
    {

    }

};

int main ()
{
  // recursion rec1;
  // rec1.triangle(cout, 3,5);

  // recursion rec2;
  // rec2.numbers(cout, THERBLIG, 2);

  recursion rec3;
  if (rec3.bears(250))
    cout << "You Won!" << endl;

  else
    cout << "You Lost! :(" << endl;

  return 0;
}
