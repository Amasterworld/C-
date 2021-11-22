/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, 
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int RobCircleHouse(vector<int> nums){
            
            int n = nums.size();
            if (n == 1) return nums[0];
            else if (n ==2) return max(nums[1], nums[0]);

            /* nums is a circle array that mean if we start at 0th then we cannot plus + the last position
             for example: nums = [2, 0, 1, 2],  then output = 2 + 1 = 3 not 2 + 2 = 4 
             but the problem is if nums = [1, 2, 9, 3, 2] our dp = [1,2, 10, 5, 12] then 12 is a sum of 1+9+2 that means all plus + 0th position
                how to know that the last value nth cannot + the dp that contains the 1st value (0th)
            
            To solve this problem: we create 2 dp array one start from 0 and 1
            and 1 starts from 1 and 2 
            */

            int dp1[n];
            dp1[0] = nums[0];
            dp1[1] = nums[1];

            int dp2[n+1];
            dp2[0] = nums[1];
            dp2[1] = nums[2];

            for (int i = 2; i< n-1; ++i){ // i < n-1 because when we do not include the last value  with the 1st value of nums

                dp1[i] = nums[i] + dp1[i-2];
                if (i >= 3) dp1[i] = nums[i] + max(dp1[i-2], dp1[i-3]);

                dp2[i] = nums[i+1] + dp2[i-2]; // i+1 because we start from 1th index then we can plus the last index of nums (i < n-1 that means max i = n -2, now i +1  hence it can reach n-1)
                if (i >= 3) dp2[i] = nums[i] + max(dp2[i-2], dp2[i-3]);

                // as the another problem we also can compact the code: dp1,2[i] = max (dp1,2[i-2]+nums[i], dp1,2[i-1] )
                // dp1,2[1] = max( nums[0], [1], nums[1],[2]);
            }
            // like b4 now we can get values of dp1 and dp2 the output should be the max of 2 last in each dp array

            for (int i = 0; i< n-1; ++i){

                cout <<dp1[i]<<" ";

            }
            cout <<endl;
            for (int i = 0; i< n-1; ++i){

                cout <<dp2[i]<<" ";

            }
            cout <<endl;
            return max ({ dp1[n-2], dp1[n-3], dp2[n-2], dp2[n-3] });

             


        }

};

int main(){
    // drive connected
    vector<int>nums = {1,2,3,1,9, 10, 11, 1};

    Solution s;
    cout << s.RobCircleHouse(nums);




}