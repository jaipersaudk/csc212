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

    int lucky7(int n)
    {

    }

    int gcb(int n, int m)
    {
      if (n == m)
        return n;

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
      if (n < 100 && n%10 == 0)
        cout << n << endl;

      if (n < 100 && n%10 !=0)
        cout << n-1 << endl;

      else
      {
        secondDown(n/10);
      }
    }

};

int main()
{
  // Testing digitDifference
  // recursion rec1;
  // rec1.digitDifference(4519,1187);

  // Testing lucky7
  // recursion rec2;
  // cout << rec2.lucky7(7) << endl;


  // Testing gcb
  // recursion rec3;
  // cout << rec3.gcb(136578,1357) << endl;

  // Tesing removeFirst
  // recursion rec4;
  // cout << rec4.removeFirst(56723) << endl;

  // Testing secondDown
  recursion rec5;
  rec5.secondDown(99);

  return 0;
}
