#include <iostream>
#include <vector>
using std::cout;



void solution(int N){

    std::vector<int> v;
    
    while (N>0)
    {
        v.push_back(N%2); // # vector can be seen as a list or array in Python, 
                                //push_back can be seen as a append 
        N /= 2;   // # in Python  N //=2 - get the an integer part of N after dividing to 2
         // for example N = 9, 9%2 = 4 reminder 1, v.push_back(1) 9/=2 get 4
         //                     4 % 2 = 2 reminder 0 v.push_back(0) 4/=2 get 2
         //                     2 %2 = 1 reminder 0 v.push_back(0)   2/=2 get 1
         //                     1 %2 = 0 reminder 1 v.push_back(0)    1/= 2 get 0
         // exist while loop

    }
    
    int count_0 =0,  max_gap = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    // after converting 10 - Binary number, we should write from 
    // down to up for example v = 0, 1, 0, 1 (N =10)
    // B num = 10101 hence, we should for revering
        {
            if (v[i] == 0)
                count_0++;                
            else if (v[i] == 1)
                {
                    max_gap = std::max(max_gap, count_0);
                
                    count_0 = 0;
                
                }

        }
    
    for (int i = v.size() - 1; i >= 0; i--)
        std::cout << v[i] << ' ';
    
    std::cout << ' '<< std::endl;
    

    cout<< max_gap<< std::endl;

     
}

int main() {


int N = 32;
solution(N);


return 0;


}
