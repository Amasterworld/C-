
#include <iostream>
using namespace std;

int main() {


    int x = 0;
    switch(x)
    {
    
    case 1: printf( "One" );
    case 0: printf( "Zero" );
    case 2: printf( "Hello World" );
    
    
    
    
    }
    return 0;

    // the output is ZeroHello World, why because when x = 0 is satisfied the second condition
    // but without break; that means all the other conditions are satisfied (until the program meets break; or the switch block is finished)
}


