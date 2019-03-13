#include <iostream>
#include <string>
using namespace std;

class Practice2
{
  public:
    void setName(string x){                 //allows us to change the variable "name"
    name = x;
      }
      string getName(){                     // allows us to get the variable "name"
        return name;
      }
/* anything outside this class has no access to whatever is private. Thats why we use "public" to change and get the variable "name"  */
  private:
    string name;
};

int main ()
{
  Practice2 bo;
  bo.setName("Kevin");
  cout << bo.getName() << endl; //we cant use bo.name because main doesnt have access to that function (its private). thats why we use bo.getName to print out the name
  return 0;
}