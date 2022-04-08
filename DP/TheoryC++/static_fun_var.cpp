#include <iostream>
using namespace std;
class Test
{
    staticVar int x = 0;  // static var, can be seen as the global variable
    //(if is used in a function, it is not deleted after return the function)
    //it must be initialized outside of class inluded it, not inside  main with
    // type data(for example int) class_name::x = suitable data type like (*)
  public:
    Test() { x++; }
    static int getX() {return x;}
};
//int Test::x = 0; // (*)
int main()
{
    // Test is a name of a class, so why can it access to its function member?
    // normally we have to do Test t; t.getX(), t is an object of a class Test
    // in this case, that means we do not need the object to access the function member
    // because , getX() is a static function.
    cout << Test::getX() << " ";  
    
    Test t[5]; // create 5 objects each object let count var increase 1, x is not reseted after each creation of object (because it is static)
    cout << Test::getX();

    // then output is 0 5
}