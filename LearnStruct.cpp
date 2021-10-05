#include <iostream>

struct Test {
    // constructor Test is a function without an argument and empty
    Test () {} 

    // constructor Test is a function with an argument and std::cout <<copy
    // the argument is a constant reference of Test stuct (Test can be seen as a int, long and so on)
    //rhs is a constant refenrece that means, read only, 
    // if rhs = "aaa" -- compile error. 
    Test (const Test& rhs) { std::cout << "copy" << std::endl; }

    // 

/*The move constructor (&&) is typically called when an object is initialized (by direct-initialization or copy-initialization) from rvalue (xvalue or prvalue) (until C++17)xvalue (since C++17) of the same type, including

    initialization: T a = std::move(b); or T a(std::move(b));, where b is of type T; */
    Test (Test&& rhs) { std::cout << "move" << std::endl; }

    Test& operator=(const Test& rhs) {
        std::cout << "assign" << std::endl;
        return *this;
    }

    Test& operator=(Test&& rhs) {
        std::cout << "move-assign" << std::endl;
        return *this;
    }
};

Test createTestObject () {
    return Test();
}

int main (int argc, char *argv[]) {
    Test a, b;

    Test c  (std::move(a));         // case 01 - a becomes invalid after copying
    
    a = c;                     // case 02
    
    //case 3: function return: return a; inside a function such as T f(), where a is of type T which has a move constructor. and it also use = an operator
    b = createTestObject();    // case 03

    //case 4: d is type of Test and it has an argument (a), obviously "copy" is made for this case
    Test d(a);                 // case 04
    return 0;
}