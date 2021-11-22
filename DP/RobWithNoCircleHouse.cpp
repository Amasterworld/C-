
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
 the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and 
 it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight 
without alerting the police.
Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/

/*SOLUTION: to find how to get the maximum amout of money, we should calculate all possible money that we can loot
then choose which one is maximum, that means we should write down all the calculation.

DP is very good to dea with it:


*/




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

    public:

        int Rob(vector<int>& nums ){

            int n = nums.size();
            if (n == 1) return nums[0];
            else if (n == 2) return max (nums[0], nums[1]);
            int dp[n+2]; // create a dp array to store amout of money
            dp[0] = nums[0];
            dp[1] = nums[1];

            for (int i = 2; i < nums.size(); ++i){
                

                dp[i] = nums[i] + dp[i-2];
                // when i >=3 the robbers can choose the house has a greater stash to loot, for exmample nums = [2,1,1,2] 
                // at i =3 nums[3] =2, the robbers can loot the 1st house and the second, ofc they choose the 1st one, money= 2 > 1 
                // note that in this problem the array is not a circle.
                if (i >= 3) {
                    dp[i] = nums[i] + max(dp[i-2], dp[i-3]);
                
                }    
                
                    //Note that: we also can compact the code as:

                    //dp[i] = max(nums[i] + dp[i-2], dp[i-1]); 
                    // but dp[1] = max(dp[0], dp[1]);
            }
        
        return max(dp[n-1], dp[n-2]);
        } 





};

int main(){

// drive code
vector <int>nums ={1,2,3,1,10};
Solution s;
cout<< s.Rob(nums);


}