#include<iostream> 
using namespace std; 
class Base { 
public: 
	Base()	 
	{ cout<<"Constructing Base \n"; } 
	virtual~Base()  // with virtual
	{ cout<<"Destructing Base \n"; }	 
}; 
class Derived: public Base { 
public: 
	Derived()	 
	{ cout<<"Constructing Derived \n"; } 
	~Derived() 
	{ cout<<"Destructing Derived \n"; } 
}; 


class Derived_1: public Derived { 
public: 
	Derived_1()	 
	{ cout<<"Constructing Derived 1 \n"; } 
	~Derived_1() 
	{ cout<<"Destructing Derived 1 \n"; } 
};
 
int main(void) 
{ 
    //Derived *d = new Derived();  // (1)
    Derived *d_1 = new Derived_1();
	Base *b = d_1;  // (2)
	delete b;   // (3)
	return 0; 
}
/*Output: (1) is executed then  pointer d is created, with new hence constructor of Derived is created
but Derived is inheriting from Base class, hence contructor of Base is created 1st then Constructor of Derived is created
Store  a derived class object into base class pointer 
(3) is executed:  In this case, we have made the destructor of base class virtual which 
will ensure that any derived class object which is pointed by a base class pointer 
object on deletion should call both base and derived class destructor.
that means when b is destroyed the both destructors (Base and Derived classes) are called
as a result : 
    Constructing Derived 
    Constructing Base 
    Destructing Base - Destructor is called in vice versus with contructor (Last make first destroy)
    Destructing Derived

now the question is : WHAT IF we have a derived_1 inhiriting Derived class but Derived class 
is using non-virtual destructor. Output:

    Constructing Base 
    Constructing Derived 
    Constructing Derived 1 
    Destructing Derived 1 
    Destructing Derived 
    Destructing Base 
so no problem
*/