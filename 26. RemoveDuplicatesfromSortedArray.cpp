/*Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same.
Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores)
Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/

/*SOLUTION: we have to do O(1) which means we can't use new array to store elements->modify directly in nums
array elements are sorted, which means that the same elements are placed next to each other. For example nums=[0,0,0,1,1,2,2,3,3,4]
Traveser the nums, whenever meets the different element, ( for example from 0 to 1) assign nums[it] (initially, it = 0), nums[it] = nums[2], it++
then when meets the 2(1 != 2) nums[it] (it now is 1), nums[1] = nums[4], keep doing.
Note that, the last element will not be assigned, then it must be assigned manually
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int removeDuplicates(vector<int> &nums){
        
        if (nums.empty()) return 0; // if nums is empty return 0
        int n =  nums.size();
        int it = 0;
        // for example nums = [0,0,0,0,0,1,1,1,2,2,3,3,4] , nums[4] != nums[5], then 
        // now, it   = 0, then nums[it] asssigned to nums[4], and it++,  nums[7] != nums[8]
        // now  it = 1, nums[1] = 1 and so on, so that means the last element WILL NOT be MOVED
        // it should be moved by manually
        for (int i = 1; i < n; ++i){
            if (nums[i-1] == nums[i]){
                nums[it] = nums[i-1]; 
                it++;
            }

        }
        // assigned the last ele
        nums[it++] = nums[n-1];
        return it;
    }



};

int main(){
    vector<int> nums = {0,0,0,0,0,1,1,1,2,2,3,3,4};
    Solution solu;
    cout<< solu.removeDuplicates(nums);
    return 0;



}