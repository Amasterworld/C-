// constexpr
#include <iostream>
using std:: cout;
using std:: endl;

const int i = 3;

constexpr int A()
{ 
        // or return 3;
        return i;
} // constexpr tell the compiler that this function always return a constant (3 for this time) during compiler time, not in RUN TIME


// if you place a below line here, np:
int arr[A() + 3]; // create an array size 6
int ii = 6;
// but without constexpr for B() function
int B()
{
    return ii;
}

//int arr_b[B()+3]; // error: array bound is not an integer constant before ']' token


int main()
{   
  
    // however if you place them in main function, so np
    int arr_b[B()+3];
    cout<<"size of array is: " <<sizeof(arr)/sizeof(arr[0])<< endl;
  
    cout<<"size of array is: " <<sizeof(arr_b)/sizeof(arr_b[0])<< endl;
   
    //cout<<"size of array is: " <<sizeof(arr_b)/sizeof(arr_b[0])<< endl;

   
   
    return 0;
}