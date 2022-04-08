#include <iostream>
using namespace std;
 
class A
{
    int x;
public:
    A(int x = 0) { cout << "A's constructor called " << endl;  
    this->x = x;
    }
};
 
class B
{
    static A a;
public:
    B() { cout << "B's constructor called " << endl; }
    static A getA() { return a; }
};
//A B::a; // definition of a with default value = 0 (1)
//A B::a(1); // definition of a with x = 1 (1)
int main()
{
    B b1, b2, b3;
    A a = b1.getA();
    return 0;
}

/* output: Compiler Error: undefined reference to `B::a'. a is a static object of a
as a static member, it should be defined ouside of main() and the class contain it.
syntax  dta_type_of_x A::x = 0;  if x is int then int A::x =0;
in this case data type of a is A, but we want to use a in B then A B::a; (1)

Note that the above program calls B’s constructor 3 times for 3 objects
 (b1, b2, and b3), but calls A’s constructor only once. 
 The reason is, static members are shared among all objects. 
 That is why they are also known as class members or class fields. Also, static members can be accessed without any object, see the below program where static member ‘a’ is accessed without any object

*/


#include <iostream>
using namespace std;
 
class A
{
    int x;
public:
    A() { cout << "A's constructor called " << endl;  }
};
 
class B
{
    static A a;
public:
    B() { cout << "B's constructor called " << endl; }
    static A getA() { return a; }
};
 
A B::a;  // definition of a
 
int main()
{
    // static member 'a' is accessed without any object of B
    A a = B::getA(); // access getA wihtout using any object
 
    return 0;
}