#include<iostream>
#include<cmath>
using namespace std;

class recursion
{
  public:
    int digitDifference(int a, int b)
    {
      if ((a < 10) && (b < 10))
      {
        cout << abs(a-b) << endl;
      }

      digitDifference(a/10,b/10);
      cout << abs(a/10-b/10) << endl;
    }

    int lucky7(int n)
    {
      if (n < 10 && n!=7)
        return n;

      else
        return n*11;
    }

    int removeFirst(int n)
    {
      if (n < 10)
        return 0;

      return removeFirst(n/10) * 10 + n%10;
    }

};

int main()
{
  recursion rec1;
  cout << rec1.digitDifference(43,27) << endl;

  // recursion rec2;
  // cout << rec2.lucky7(747) << endl;
  //
  // recursion rec4;
  // cout << rec4.removeFirst(56723) << endl;

  return 0;
}
