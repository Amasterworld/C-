/*

unique_ptr<> is one of the Smart pointer implementation provided by c++11 to 
prevent memory leaks. A unique_ptr object wraps around a raw pointer and 
its responsible for its lifetime. When this object is destructed then in 
its destructor it deletes the associated raw pointer.

unique_ptr has its -> and * operator overloaded, so it can be used similar to 
normal pointer.  */

#include <iostream>
#include <memory>

struct Task{ 

    int id;
    //constructor parameterize
    Task(int x) :id(x)
    {
        std::cout<<"constructor is called "<<std::endl;
    } 
    ~Task(){
        std::cout<<"destructor is called  "<<std::endl;        
    }

};
int main()
{
    // using unique_ptr 
   // Task* ptr = new Task (1);
   // std::cout<<"access to id by raw pointer "<<ptr->id <<std::endl;
    // so now if want to  call the destructor we need:
   // delete ptr;
   // so if we forget to delete ptr, the program cam be leak memory
   // to avoid  this problem, we can use smart pointer
    Task* p =  new Task(2);
    std::unique_ptr<Task> u_ptr (p); 
    std::cout<<" access to id by smart pointer "<<u_ptr->id <<std::endl;

    /*Output : 
                constructor is called 
                access to id by smart pointer 2
                destructor is called  
    - why? no delete u_ptr
    */
    return 0;

}





