#include<iostream>
using namespace std;
  
class Test
{
private:
  int x;
  int y;
public:
  Test(int x = 0) {
      cout<<"construtor is calling"<<endl;
       this->x = x; 
    }
    // delete default int x = 0, int y = 0, otherwise creates an error ambiguous, 
    // when Test obj(6) for example then the both constructor can be created -> error
    // now MUST 2 parameters then the below constructor is created
    Test (int x, int y){
        cout<<"construtor with 2 parameters is calling "<<endl;
        this->x = x;
        this->y = y;
    }
  // original:
  //void change(Test *t){this = t};
  // add const to avoid change t without notifying this cannot be = t, then this->x = t
  // but now if we run the program, the compiler still gives us an error because *ptr is a pointer points to 
  // the constructor 2 parameters, what we need is its content (x) hence point to x
  void change(const Test *t) { this->x = t->x; }
  
  void print() { cout << "x = " << x << endl; }
};
  
int main()
{
  Test obj(5);
  obj.print();
  cout<<"between calling "<<endl;
  Test *ptr = new Test(10, 20);// also call the constructor if have new Test(10)
  obj.change(ptr);
  obj.print();
  return 0;
}