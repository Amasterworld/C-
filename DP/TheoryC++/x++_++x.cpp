#include <iostream>
using namespace std;

int main(){
    int x, y, z;
    x = 5; y = 0, z = 0;
    //x++ is postfix, ++x is prefix ++
    y += ++x + 5; // ++x is executed 1st the ++x = 6, y += 6+5 then y = 0+11--> cout <<y, the output is 11

    cout <<"x="<<x<< " y = "<<y<< endl;
    x = 5; // reset x = 5 
    z += x++ + 5; // execute z += 5+5 then z = 10 and x++ = 6
    cout <<"z = "<<z;
    return 0; 




}
