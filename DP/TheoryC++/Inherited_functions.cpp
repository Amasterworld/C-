//What is the output of the following code snippet?
#include<iostream>
struct A {
	void print(bool a)           { std::cout << "A bool" << std::endl; }
	virtual void print(char c)   { std::cout << "A char" << std::endl; }
	void print(double b)         { std::cout << "A double" << std::endl; }
};
struct B : A {
	void print(bool a)           { std::cout << "B bool" << std::endl; }
	void print(char c)           { std::cout << "B char" << std::endl; }
	virtual void print(double b) { std::cout << "B double" << std::endl; }
};

int main( ) {
	A a;
	B b; B* bp = &b;
	A* ba = &a;
	ba->print( '1' );
//output is "A char" even it has a virtual keyword
//in this case, raw pointer ba pointing to ref of obj a
	


	A* baa = bp;
	baa->print( '1' );
	//output is "B char" because now ba pointing to bp and B is inhering from class A and it has a virtual keyword
	// that means it can be redefined in the derive class
	
	baa->print(1.0 );
	//output is "A double" because now ba pointing to bp and B is inhering from class A 
	//but this function does not have keyword virtual so, it cannot be redefined in B 
	baa->print(true); // output is "A bool"

}