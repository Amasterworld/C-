/*Find the maximum of subarrays for example A= [-1, -2, 4, -1, -2, 1, 5, -3]
hence the maximum of subarrays is: 4 + -1 + -2 + 1 + 5 = 7

solution: DP(dynamic programming) 
*/
#include <iostream>
#include <vector>
using namespace std;
int FindMaxximumSubarray(const vector<int>& Input_Array){
    int sum =0, min_sum = 0, max_sum =0;
    for (int i = 0; i < Input_Array.size(); ++i){
        sum += Input_Array[i];
        
        if (sum < min_sum) min_sum = sum;
        cout <<"sum = "<<sum<< " min sum " <<min_sum<<endl;
    }
    if (sum - min_sum > max_sum) max_sum = sum -min_sum;       
    return max_sum;
}
int main(){
    //vector<int> A ={-1, -2, 4, -1, -2, 1, 5, -3};
    vector<int> A ={5, -6 ,2 ,4};
    cout << FindMaxximumSubarray(A)<<endl;

    return 0;
}