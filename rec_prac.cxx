#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class recursion
{
  public:
    int digitDifference(int a, int b)
    {
      // base case
      if ((a < 10) && (b < 10))
        cout << abs(a-b) << std::flush; //std::flush keeps the output on the same line

      if ((a >=10) && (b>=10))
      {
        digitDifference(a/10,b/10);
        cout << abs((a%10)-(b%10)) << std::flush; //std::flush keeps the output on the same line
      }
    }


    // Couldnt figure out
    /*int lucky7(int n)
    {

    }*/

    int gcb(int n, int m)
    {
      // base case
      if (n == m)
        return n;

      // keep reducing until they both have the same digits or equal 0
      if (n != m)
      {
        if (n > m)
          gcb(n/10,m);

        else
          gcb(n,m/10);
      }
    }

    int removeFirst(int n)
    {
      if (n < 10)
        return 0;

      return removeFirst(n/10) * 10 + n%10;
    }

    int secondDown(int n)
    {
      if (n < 100)
      {
        if (n%10 == 0)
        {
          return n;
        }
        return n-1;
      }

      return secondDown(n/10) * 10 + n%10;
    }

    int diff2(int n)
    {
      if (n < 10)
        return n;

      if (n < 100)
      {
        int q = n/10; //quotient
        int r = n%10; //remainder
        int m = abs(q-r); // difference between the first two digits in n
        return m;
      }

      // divide by 10 until number is smaller than 100
      else
        diff2(n/10);
    }

    int add7(int n)
    {
      if (n == 0)
        return 7;

      else
        return add7(n/10) * 10 + n%10;
    }

    int removeLast7(int n)
    {
      if (n == 0)
        return 0;

      if (n%10 == 7)
        return n/10;

      return 10 * removeLast7(n/10) + n%10;
    }

};

/*
int main()
{
  // Testing digitDifference
  recursion rec1;
  rec1.digitDifference(4519,1187);

  // Testing lucky7
  recursion rec2;
  cout << rec2.lucky7(7) << endl;

  // Testing gcb
  recursion rec3;
  cout << rec3.gcb(136578,1357) << endl;

  // Tesing removeFirst
  recursion rec4;
  cout << rec4.removeFirst(56723) << endl;

  // Testing secondDown
  recursion rec5;
  cout << rec5.secondDown(1234)+1 << endl;

  // Testing diff2
  recursion rec6;
  cout << rec6.diff2(7) << endl;

  // Testing add7
  recursion rec7;
  cout << rec7.add7(4567) << endl;

  // Testing removeLast7
  recursion rec8;
  cout << rec8.removeLast7(1727) << endl;

  return 0;
}
*/
