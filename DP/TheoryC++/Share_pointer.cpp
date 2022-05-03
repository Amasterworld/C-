// share pointer
#include <iostream>
#include <string>
#include <memory>
using std::cout;
using std::endl;
using std::string;

class Dog
{   
private:
    string name;
public:
    //constructor
    Dog(string name ="NO NAME")
    {
        cout<<"Dog is created: "<< name<<endl;
        this->name = name; // this-> to var "name" of this class
    }
    // Destructor
    ~Dog()
    {
        cout<<"Dog is destruced "<< this->name<<endl;
    } 
    string getName() const{
        return this->name;
    }
    // Function
    void bark()
    {
        cout<<"Dog is barking: "<< this->name<< "Arrrrang ang ang "<<endl;
    }
}; 
void foo()
{
    Dog* ptr = new Dog("Gunner");// create a pointer and object, dog namely, Gunner
    
    //... do sth..
    //do not use ptr anymore we should delete it otherwise  memory leak
    delete ptr;

    // but now we need to use ptr again 
   // ptr->bark(); // error because ptr was deleted, dangling pointer 

  // if we delete ptr so early, if we want to reuse it again, dangling pointer, if we forgot to delete it, we can run into memory leak
  // tracking to delete every object, it is hard and tedious work and 
  //--> solution: SMART POINTER
  std::shared_ptr<Dog> p (new Dog("Gun")); // count 1
  // not very safe because: 1 "Gun" is created; 2 pointer "p" is created,then what if "p" could not create after compiler finished (1)
  // the mean it never can be deleted --> memory leak.
  std::shared_ptr<Dog> p2 = p;  // Count 2, p2 also points to  object Dog("Gun")
  p->bark();
}

int main()
{
    foo();

    Dog* d = new Dog(); //no name dog -  bad idea to use with smart pointer
    // now create a shared pointer to raw pointer
    
    std::shared_ptr<Dog> p (d); // p.use_count() == 1 , use_count() is its own member, this method is used to return how many pointers are pointing to obj.
    // if p2 also points to d
    // std::shared_ptr<Dog> p2(d);//p2.use_count() == 1
    // -->ERROR because: if p is going outside the scope, the d is destroyed, and then when p2 goes outside its cope, d is destroyed again
    //--> undefined behavior. it is not good to use smartpointer as above
    // so use like below is better
   // std::shared_ptr<Dog> pt (new Dog("Gun")); // count 1
  
 //   std::shared_ptr<Dog> pt2 = pt;  // Count 2, p2 also points to  object Dog("Gun")

    // or even better:
   std::shared_ptr<Dog> p_best = std::make_shared<Dog>("Tank"); //fater and safer 
   std::shared_ptr<Dog> p2_best = p_best; 
   std::shared_ptr<Dog> p3_best = p_best;
   cout<<"the number of pointer is pointing to dog, namely, "<< p_best->getName() <<", is "  <<p_best.use_count()<<endl;;
   //no error when run out of the scope, in this case when reach return 0
    return 0;
}