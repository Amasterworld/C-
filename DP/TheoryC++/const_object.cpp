#include <iostream>
using namespace std;
class Point
{
    int x, y;
  public:
   Point(int i = 0, int j =0)
   { x = i; y = j;  }
   int getX() const { return x; }
   int getY() {return y;}
   //int getY() const {return y;}
};
 
int main()
{
    const Point t;
    cout << t.getX() << " ";
    cout << t.getY();
    return 0;
}

/*  Predict output:
a) 0 0
b) Garbage values
c) Compile error
d) Segmentation fault
-- Answer: c.
because of const Point t; hence t is const object, C++ does not allow 
a const object to access non-const member function, and int getY is not const
to solve that matter: - 1st solution: delete const for Point t; (that means t is not const object anymore)
                      - second solution: add const for getY

*/