

 /*
    Write a class “Integer” such that following main function works and outputs “2343”.
int main(){
Integer i(1);
Integer j(2);
Integer k(3);
std::cout << j;
j = 3;
std::cout << j;
k = i + j;
std::cout << k;
std::cout << Integer::amount();
return 0;
}
 
 */


#include <iostream>

class Integer{

public:


    //constructor
    Integer(int x) : _x(x){
        ++cnt_instance; // count the number of instance created
    }

    //destructor
    ~Integer(){
        --cnt_instance; // count the number of instance deleted
    }

    Integer& operator= (int x){
        
        _x = x;
        return *this;
    }

    Integer& operator=(const Integer& other){
        
        _x = other._x;
        return *this;
    }

    Integer operator+(const Integer& other){
        
        return Integer(_x + other._x);
    }

    friend std::ostream& operator << (std::ostream& os, const Integer& other){
        os <<other._x;
        return os;
    }

    static unsigned amount(){
        return cnt_instance;
    }

private:
    int _x;
    static unsigned  cnt_instance;

};

// cnt_instance is a static var so it should be initialized outside of the class 
unsigned Integer::cnt_instance = 0;

int main(){

    Integer i(1);  // constructor with input
    Integer j(2);
    Integer k(3);
    std::cout << j; // should overloading operator <<
    j = 3; // should overloading operator =
    std::cout << j;
    k = i + j;
    std::cout << k;
    std::cout << Integer::amount(); // static function 
    return 0;

}