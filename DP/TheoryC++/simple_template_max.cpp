// simple template to get the maximum between two numbers
// two numbers can be int, double or float even chars
// we cannot do int max (int &a, int &b); because if a and b is double we shoudl change again
#include<iostream>
using namespace std;

template <class T> T max(T& a, T& b){
    return (a > b ? a : b);
}

int main(){

    int  x = 5, y = 6;
    double a = 5.5, b = 4.4;
    int temp1 = max(x, y);
    double temp2 = max(a, b);
    cout << temp1 << " " << temp2;
    return 0;
    
}