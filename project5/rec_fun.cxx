#include <iostream>
#include <string>
// #include <strclass.h>

using namespace std;

class recursion
{
  public:
    /*void triangle(ostream& outs, unsigned int m, unsigned int n)
    {
      // precondition
      if (m>n)
        return;

      else
      {
        if (m == 0)
          return;
          else
          {
            for (int i = m; i <= n; i++)
            cout << "*";

            cout << "\n";

            triangle(outs, m-1, n);
            for (int i = m; i <= n; i++)
            cout << "*";

            cout << "\n";

          }
      }

    }*/

    void triangle(ostream& outs, unsigned int m, unsigned int n)
    {
      // precondition
      if (m > n)
        return;

      else
      {
        if (m==0)
          return;

        else
        {
          for (int i = 0; i < m; i++)
            outs << "*";

          outs << "\n";

          triangle(cout, m+1, n);

          for (int i = 0; i < m; i++)
            outs << "*";

          outs << "\n";
        }
      }
    }

    void numbers(ostream& outs, const string& prefix, unsigned int levels)
    {
      if (levels == 0)
      {
        cout << prefix << endl;
        return;
      }

      for (int k = 0; k < 10; k++)
        cout << prefix << "." << k << endl;

      if (levels <=1)
        numbers(outs, prefix, levels - 1);
      cout << "\n";
    }

    /*bool bears(unsigned int n)
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
    */

    bool bears(int n)
    {
      if (n == 42)
        return true;

      if (n < 42)
        return false;

      if (n % 2 == 0 && bears(n/2))
        return true;

      if (n % 5 == 0 && bears(n-42))
        return true;

      if ((n%3==0) || (n%4==0))
      {
        int i = n%10;
        int j = ((n%100)/10);
        n = n-(i*j);
        return (bears(n));
      }

    }

    /*void pattern(ostream& outs, unsigned int n, unsigned int i)
    {
      if (n == 1)
        outs << "*" << endl;

      else
      {
        pattern(cout, (n/2), i+1);
        for (int j = 0; j < n; j++)
          outs << "*";

        outs << "\n";

        for (int j = 0; j < i; j++)
          outs << "*";

        pattern(cout,(n/2), i+1);
      }
    }*/
    /*void pattern(ostream& outs, unsigned int n, unsigned int i)
    {
      if (n == 1)
        outs << "*" << endl;

      else
      {
        pattern(cout, (n/2), i+1);
        for (int j = 0; j < n; j++)
          outs << "*";

        outs << "\n";

        for (int j = 0; j < i; j++)
          outs << " ";

        pattern(cout,(n/2), i+1);
      }
    }
    */

    void pattern(ostream& outs, unsigned int n, unsigned int i)
    {
      // base case
      if (n == 1)
      {
        for (int j = 0; j < i; j++)
          outs << " ";
        outs << "*";
      }

      else
      {
        pattern(outs, n/2, i);
        cout << "\n";
        for (int k = 0; k < i; k++)
          outs << " ";
        for (int m = 0; m < n; m++)
          outs << "* ";
        outs << endl;
        pattern(outs, n/2, n+i);
      }
    }

};

int main ()
{
  recursion rec1;
  rec1.triangle(cout, 4, 11);

  cout << endl;

  // recursion rec2;
  // rec2.numbers(cout, "THERBLIG", 0);

  cout << "\n";

  recursion rec3;
  if (rec3.bears(53))
    cout << "You Won!" << endl;

  else
    cout << "You Lost! :(" << endl;

  cout << "\n";

  recursion rec4;
  rec4.pattern(cout, 8, 0);

  return 0;
}
