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
        std::cout<<"destructor is called now "<<std::endl;        
    }

};
int main()
{
    // using unique_ptr 
   // Task* ptr = new Task (1);
   // std::cout<<"access to id by raw pointer "<< ptr->id <<std::endl;
    // so now if want to  call the destructor we need:
   // delete ptr;
   // so if we forget to: delete ptr; the program cam be leak memory
   // to avoid  this problem, we can use smart pointer
    Task* p =  new Task(2); //(1)
    std::unique_ptr<Task> u_ptr (p); 
    //  std::unique_ptr <Task> u_ptr (new Task(2)); 
    std::cout<<" access to id by smart pointer "<<u_ptr->id <<std::endl;
    
    /*Output : 
                constructor is called 
                access to id by smart pointer 2
                destructor is called  
    
    - why? no delete u_ptr; or delete p;  the constructor was called?
    
    */

    // we also can make a smart pointer point to nullptr or without initilization raw pointer access
    std:: unique_ptr <Task> u2_ptr;
    // now check to ensure that u2_ptr is empty
    if (!u2_ptr){
        std::cout<< "Empty pointer "<<std::endl;
    }
    // or:
    if (u2_ptr == nullptr){
        std::cout<< "Empty pointer "<<std::endl;
    }
    // To create a unique_ptr<> object that is non empty, we need to pass  the 
    //raw pointer in its constructor while creating the object i.e. like (1) OR

    std::unique_ptr <Task> u3_ptr (new Task(50));
    std::cout<<"access to id by the smart pointer "<<u3_ptr->id<<std::endl;
   
    //NOTE:

    /*
    We can not create a unique_ptr<> object through assignment, 
    otherwise it will cause compile error
    std::unique_ptr<Task> taskPtr2 = new Task(); // Compile Error
    in (1): Task* p =  new Task(2); // no problem
    */

   // release ownership of smart pointer
    if (u3_ptr != nullptr)
    {
      std::cout<< "b4 releasing  u3_ptr is NOT empty, it points to id with the value:  "<<u3_ptr->id <<std::endl;    
    }

   Task *p_rel = u3_ptr.release();
   if (u3_ptr == nullptr)
    {
      std::cout<< "after releasing now u3_ptr is empty "<<std::endl;    
    }

    std::cout<<"the value of p_rel can point to id with the value "<< p_rel->id<<std::endl;


    return 0;

}





