
/* why do we need to use the array pointer here? 
    the size of the pointer is const (8 byte for OS 64 bits)
    for example if we want to swap two big strings or arrays
    with the classic method we have to create the middle string or array to contain 1 string and then swap
    with the pointer array or string they are always 8 byte



*/









#include <iostream>
#include <string>
using namespace std;

int main(){

    string s1 = "Alex";
    string s2 = "Urbango";

    string *p1, *p2, *p;

    cout <<  s1 << endl;
    cout <<  s2 << endl;

    cout <<  "after swapping: " << endl;
    p1 = &s1;
    p2 = &s2;
    
     
    p = p1;
    p1 = p2;
    p2 = p;

    cout <<*p1<< endl;
    cout <<*p2<< endl;


    return 0;
}