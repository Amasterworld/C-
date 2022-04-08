#include<iostream> 
using namespace std; 
class Base { 
public: 
	Base()	 
	{ cout<<"Constructing Base \n"; } 
	~Base() // virtual ~Base()
	{ cout<<"Destructing Base \n"; }	 
}; 
class Derived: public Base { 
public: 
	Derived()	 
	{ cout<<"Constructing Derived \n"; } 
	~Derived() 
	{ cout<<"Destructing Derived \n"; } 
}; 

 
int main(void) 
{ 
	Derived *d = new Derived(); 
	Base *b = d; 
	delete b; 
	return 0; 
}

//output: 
/*
Constructing Base 
Constructing Derived 
Destructing Base

Explanation: As we are storing  a derived class object into base class pointer therefore
when the b is destroyed, the program has not called the Derived class destructor -> d is not destroyed
-> unsual behavior
-> to solve the problem: using virtual destructor add: virtual ~Base()
*/