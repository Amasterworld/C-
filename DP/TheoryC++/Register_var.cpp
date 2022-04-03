        #include <iostream>
        using namespace std;
        
        int main()

        {

            register int i = 1;// Compiler error may be possible
            // as we know: The register keyword is a request to the compiler that the
            // specified variable is to be STORED in a register of the processor 
            //instead of memory as a way to gain speed, mostly because 
            //it will be heavily used. The compiler may ignore the request. 
            
            // that means i can have NO address in the memory 
            //then and finding the address of it is illegal. 
            int *ptr = &i;

            cout << *ptr;

    	return 0;

        }