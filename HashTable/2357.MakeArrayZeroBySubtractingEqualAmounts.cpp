/*
2357. Make Array Zero by Subtracting Equal Amounts - leetcode

You are given a non-negative integer array nums. In one operation, you must:

    Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
    Subtract x from every positive element in nums.

Return the minimum number of operations to make every element in nums equal to 0.

Example 1:

Input: nums = [1,5,0,3,5]
Output: 3
Explanation:
In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].

Example 2:

Input: nums = [0]
Output: 0
Explanation: Each element in nums is already 0 so no operations are needed.

SOLUTION: this problem is very easy if we can understand its trick, from the example 1: we can easily see that the number 0 should be not counted, 
the repeated numbers do not effect to the result (two  5  or three 5 numbers does not effect the result) -> using set or unordered_set to delete repeated numbers
The order of the numbers in the set does not affect the result -> unordered_set is faster than set (for the larger number, but unordered_map uses more memory)

*/
#include<iostream>
#include<vector>
#include<unordered_set>
class Solution{

public:
    int minimumOperations(std::vector<int>& nums) {
        std::unordered_set<int> un_set_nums;
        for (auto num : nums){
            if (num != 0){
                un_set_nums.insert(num);
            }
            
        }
        return un_set_nums.size();
    }
};

int main(){
    
    std::vector<int> nums = {1, 5, 0, 3, 5};
    Solution s;
    std::cout<<s.minimumOperations(nums)<<std::endl; // output 3 - correct
    //std::vector<int> nums = {0};
    std::cout<<s.minimumOperations(nums)<<std::endl; // output 0 - correct
    return 0;


}