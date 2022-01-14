/*16. 3SumClosest 
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution. 

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0

*/
/* SOLUTION: it is more or less the same the problem to  find 3SUM = target, but now we have to create int closest variable to track the 3SUM 
closest the target


*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:

    int threeSumClosest(vector<int> & nums, int target){
        // sort the ele in an array 
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int temp, track  = INT_MAX;
        int closest;
        for (int i = 0; i < n; ++i){

            if (i > 0 && nums[i-1] == nums[i]) continue; // ignore the repeatable elements from i >0, for example [-1,-1,-1,-1,0,0,1,1,1,1]
            int l = i+1, r = n-1;
            while (l < r){

                int ThreeSumNums = nums[i] + nums[l] + nums[r];
                temp = min(temp, abs(temp - ThreeSumNums));
                if (track != temp){
                    track = temp;
                    closest = ThreeSumNums;  // assign the closest  = 3sumNums, until temp never != track then we get the the sum cloest the target.
                }
                if ( ThreeSumNums == target){
                    return ThreeSumNums;
                }
                else if (ThreeSumNums > target){
                    r--;
                }
                else if (ThreeSumNums < target){

                    l++; 
                }

            }



        }
        return closest;

    }

};

int main () {

    vector<int> nums =  {4,1,-3,0};
    int target = 4;

    Solution solu;
    cout<< solu.threeSumClosest(nums, target);
    return 0;



}