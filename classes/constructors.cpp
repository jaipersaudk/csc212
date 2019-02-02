#include <iostream>
using namespace std;

class KevinsClass{
/* constructors are functions that get called automatically when you create an object
 * compilers automatically create a constructor but it is better to create your own
 * Constructor names are ALWAYS the name of the class
 * Purpose: give variables an inital value; when the object is created (objects can have parameters, it is best to give variables a value
 */
  public:
    KevinsClass(){          //constructor
      cout << "this is will get printed automatically" << endl;
    }
};

class KevinsClass2{
  public:
    KevinsClass2(string z){
      setName(z);
    }

    void setName(string x){
      name = x;
    }

    string getName(){
      return name;
    }

    private:
      string name;
};

int main ()
{
  KevinsClass bo; //constructor is called automatically after this line
  KevinsClass2 bo2("Kevin"); // "Kevin" is the value for z, then x, then name. So the value for name after the object is create is "Kevin"
  KevinsClass2 bo3("Jaipersaud");
  cout << bo2.getName() << endl;
  cout << bo3.getName() << endl;

/* Each object has its own set of variables. this is why object bo2 wasnt overwritten with object bo3. Each object is assigned its set of variables.  */


  return 0;
}