#include <iostream>
using namespace std;
class A
{  
    private:
    static int y; // note that default y is private
    public:
        static int x;
        static int getX() {return x;}
        static int getY() {return y;}
};
// to access static member should be used: Scope resolution operator(::)
// and the below line should be written outside of the class A and not inside main() 
int A::x = 100;         // STATIC MEMBER VARIABLE x DEFINITION

int A::y = 1000; //note that y is  private number

int main()
{
   //A::x = 100;    // REMOVE int FROM HERE
   cout<<A::getX()<<endl; // the function 
   cout<<A::getY()<<endl; // the function 
   cout<<A::x<<endl; //ok
   cout<<A::y<<endl;
   return 0;
}