// share pointer
#include <iostream>
#include <string>
#include <memory>
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

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
        cout<<"Dog is destructed "<< this->name<<endl;
    } 
    string getName() const{
        return this->name;
    }
    // Function
    void bark()
    {
        cout<<"Dog is barkings: "<< this->name<< "Arrrrang ang ang "<<endl;
    }
}; 
void foo()
{
   
   shared_ptr<Dog> p1  = make_shared<Dog>("Gunner");
   shared_ptr<Dog> p2  = make_shared<Dog>("Tanker");
   //-- 3 ways to delete Dog Gunner

      //p1 = p2; // Dog Gunner now is deleted, now p1 points to Dog Tanker
      // p1 = nullptr; // Dog Gunner now is deleted,
      //p1.reset();// Dog Gunner now is deleted,

   // if p1.use_count() return the number of pointers pointing to the object, then p1.get() return the raw pointer pointing to the object
    Dog* d = p1.get();
    
    cout<<"name of the dog is "<< d->getName()<<endl;
    // so now if 
    // delete d; // can be error, because when p1 goes out the scope that Dog Gunner will be deleted again, 

    //custom deleter, in the above, we use shared_ptr to create 

    shared_ptr<Dog> p3 = shared_ptr<Dog>(new Dog("Slayer"), [] (Dog* p){cout<< "Custom deleting: "; delete p;} );

    // now
    shared_ptr<Dog> p4 (new Dog[3]); 
    
    //    output: ................
    //        Dog is created: NO NAME
    //        Dog is created: NO NAME
    //        Dog is created: NO NAME
    //        Dog is destructed NO NAME
    //    we create 3 Dog NO NAME but only 1 was destructed that means 2 Dog NO NAME never are destructed --> mem leak

    // to SOLVE that matter, using lamda function to make a custum deleter
    shared_ptr<Dog> p5 (new Dog[3], [] (Dog* p) {delete[] p;}  ); // now all 3 DOG NO NAME are deleted when p5 goes out of the scope
}
    

int main()
{
    foo();

    return 0;
}