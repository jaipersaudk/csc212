#include <iostream>
#include "stats.h"
#include "stats.cpp"

using namespace std;

int main()
{
  statistician s;
  s.next(1.1);
  s.next(2.8);
  s.next(-0.9);

  cout << s.mean() << endl;


  return 0;
}
