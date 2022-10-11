/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.

Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.

Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

Time complexity should be O(n)
 
*/


/*SOlution:  very simple solution is using the 3 for-loops  and check the conditions, of course it is not good solution, TC O(n*n*n)
better solution is: using two vars, first and second to track the values of first and second of the triple. Traveser the nums, whenever we get the value smaller than first, assign it to the first
, if we meets firs < nums[i] <=Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.

Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.

Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

  second, assign it to the second, and if all above condtion is fail return true(because that means nums[i] > second > first.

TC O(n), SC O(1). */

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int first = INT_MAX, second =  INT_MAX ;
        
        for (int i = 0; i < nums.size(); ++i){
            
            if (nums[i] <= first){ // get the first 
                
                first = nums[i];
            }
            else if(nums[i] <= second){ // if the nums[i] > first and <= second
                
                second = nums[i];
            }
            else{ // if all above conditions are incorrect that means nums[i] > second > first then
                return true;
            }
        }
        return false;
        
        
    }
};
