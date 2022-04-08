//Lamda expression, predict output: is ERROR
//because the capture ([]) by default is capturing by value, 
//thefore the value cannot be changed (remember that normal function is diff, without referecen
//normal function create a copy and it will be a local variable(does not change outside))
//because the value of var a cannot be change -> ERROR
//SOLUTION: change a is global var as: static int a = 5;
// OR change capture of lamda expression to be referecen as : [&a]

#include<iostream>
using namespace std;
int main()
{
	 int a = 5;
	 //lamda expression
	auto check = []()  
        {
		a = 10;
	};
	check();
	cout<<"Value of a: "<<a<<endl;
	return 0;
}