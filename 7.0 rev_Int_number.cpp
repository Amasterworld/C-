//Given a signed 32-bit integer x, return x with its digits reversed. 
//If reversing x causes the value to go outside the signed 32-bit integer range 
//[-2 pow 31, 2 pow 31 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers
// (signed or unsigned).
#include <iostream>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

class Solution{

    public:
        int  reverse(int x){
            cout<< INT_MAX<<" "<< INT_MIN<<endl;

            int ans = 0, remain_num =abs(x), len_x = to_string(x).length();

            for (int i = 0; i < len_x; ++i){
                
                // for example x= 123, then 1st iter 123%10 get 3, 2nd iter 3 = 3*10 +(12%10)->32 
                // now we have a problem INT_MAX and MIN are 2147483647  -2147483648
                // that mean if ans*10 > INT_MAX throw an error, should check it
                // but it raise a problem for example x = 1463847412 -->rev = 2147483641
                //-> acceptable then
                if ( ans > INT_MAX/10) return 0;
                else if (ans < INT_MIN/10) return 0;
                ans = ans*10 + (remain_num %10);
                remain_num /=10 ; 


            }
            return x >0 ? ans: -ans;

        }

};

int main(){

    int x = 1463847412;
    Solution s;
    cout<<s.reverse(x);
    

}