#include <iostream>
using namespace std;
class A{
public:
//	A(){
		//cout<<"Constructor called\n";
	//   }
    A(int i = 0 ){cout<<"paramiterize Constructor "<<endl;}
	~A(){
		cout<<"Destructor called\n";
	    }
};
int main(int argc, char const *argv[])
{
	A a[3];
    //A *a  = new A[5];
	//delete a; if  A *a  = new int[5]; then a is a pointer then we should use delete[] a 
    // or even A * a = new A, hence we can use delete a; 
    //delete[] a;
	return 0;
}




