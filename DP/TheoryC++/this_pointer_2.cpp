#include<iostream>
using namespace std;
class Test
{
   private:
     static int count;
   public:
     Test& fun();   // 
};
int Test::count = 0;
Test& Test::fun() // (1)
{
    Test::count++;
    cout << Test::count << " ";
    return *this;  // this means pointer to the object, so *this is an object. 
    //So you are returning an object ie, *this returns a REFERENCE ()
    //to the object.
}
int main()
{
    Test t;
    t.fun().fun().fun().fun();  // note that fun() returns the same object by reference
    // that is why we can use: t.func().func()... multi times
    return 0;
}