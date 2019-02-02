#include <iostream>
using namespace std;

class KEVIN
{
  public:     // able to use the functions in main (outside of the class)
    void coolSaying() {
      cout << "lol" << endl;
    }
};

int main ()
{
/*   objects know what class you are working with (how you access the functions in your class */
  KEVIN KevinObject; /* first the class and then type a name for a object*/
  KevinObject.coolSaying(); /* now type object name, dot, and then the function (allows us to access the class) */

  return 0;
}
