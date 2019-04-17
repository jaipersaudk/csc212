#include <iostream>
#include <string>

using namespace std;

class recursion
{
  public:
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
      // base case
      if (levels == 0)
      {
        cout << prefix << endl;
        return;
      }

      for (char c = '1'; c <= '9'; c++)
      {
        if (levels == 1)
        {
          string s = (prefix + c);
          numbers(outs,s,levels-1);
        }
        if (levels > 1)
        {
           string s2 = (prefix + c) + '.';
           numbers(outs,s2,levels-1);
        }
      }
    }

    bool bears(int n)
    {
      // base case 1
      if (n == 42)
        return true;

      // base case 2
      if (n < 42)
        return false;

      // case when n is divisible by 2
      if (n % 2 == 0 && bears(n/2))
        return true;

      // case when n is divisible by 5
      if (n % 5 == 0 && bears(n-42))
        return true;

      // math computation for the case if n is divisible by 3 OR 4
      int i = n%10;
      int j = ((n%100)/10);

      // case when n is divisible by 3 OR 4
      if (((n%3 == 0) || (n%4 == 0)) && bears(n-(i*j)))
        return true;

      else
        return false;

    }

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

  // testing triangle function
  recursion rec1;
  rec1.triangle(cout, 4, 11);

  cout << endl;

  // testing numbers function
  recursion rec2;
  rec2.numbers(cout, "THERBLIG", 3);


  cout << "\n";

  // testing bears function
  recursion rec3;
  if (rec3.bears(250))
    cout << "You Won!" << endl;

  else
    cout << "You Lost! :(" << endl;

  cout << "\n";

  // tesing pattern function
  recursion rec4;
  rec4.pattern(cout, 8, 0);

  return 0;
}
