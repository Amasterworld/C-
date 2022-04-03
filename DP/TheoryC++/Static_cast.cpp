        #include <iostream>

        using namespace std;

        int main()

        {

            int n = 5;

            void *p = &n;

            int *pi = static_cast<int*>(p);   // (*)
            //just convert from void to int 
                // so *pi will print 5
            cout << *pi << endl;
            // note that *p is void pointer that means it points to address of var n
            // but it receive void, if cout<<*p; error however if we change int *p = &n;
            //and cout<<*p -> output is 5, 
            // (*) is casted from void pointer p to int and assign it to pointer pi 
            return 0;

        }