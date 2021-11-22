/*

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
*/


/* SOLUTION: Fibonaci number with dynamic programming and recursive

*/
#include <iostream>
using namespace std;

// dynamic programming
int fiboNumber(int n){
    int f[n+1]; // create an array f to store the fibonaci numbers
    if (n < 1) return  n;
    f[0] = 0;
    f[1] = 1; 

    for (int i = 2; i <= n; i++){

        f[i] = f[i-2] + f[i-1];

    } 

    return f[n];
 // this solution is very good, because  it can re-use the value for example if we want to calculate 
 // fiboNumber(5) = fiboNumber(4) + fiboNumber(3), then the program does not need to 
 //re-calcualte fiboNumber(4) and fiboNumber(3) again
 //CONS: consuming the mem to store the array
}
// recursive solution:

int fibRecuSolu(int n){
    if (n <= 1) return n;
    return fibRecuSolu(n -1) + fibRecuSolu(n -2); 



}





int main() {
    // driver code

    int n = 10;
    cout << fiboNumber(n)<< endl;
   
    cout <<fibRecuSolu(n);


}