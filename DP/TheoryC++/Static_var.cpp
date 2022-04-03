#include<iostream>
using namespace std;
  
int& fun()
{
    static int x = 10;// as global var will not be delete after return
    return x;
}
int main()
{
    fun() = 30;
    cout << fun()<<endl;
    
    return 0;
}