#include<iostream>
int main(){
    int a = 1;
    int b = 1;
    int* pa  = &a;
    int* pb = &b;
    
    std::cout<< (pa == pb)<<'\n';// pa and pb here are the address of objects that they are pointing to, pa pointing to a, pb pointing to b
    // a and b are different hence OUTPUT is 0 (false)
    
    /*now we change like this*/
    int* pc = &a;
    int* pd = &a;
    std::cout<<(pc == pd)<<'\n';// now both pointers are pointing to var a, hence OUTPUT is 1 (true)
    /*so now what is &pa and &pb*/
    std::cout<<"pa "<<&pa<<" pb "<<&pb<<'\n'; // they are address of pointer pa and pb in the memory 0xdasdad and they are diff
    std::cout<<(&pa == &pb)<<'\n';// output 0

    return 0;
}