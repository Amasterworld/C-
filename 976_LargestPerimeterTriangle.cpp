/*976.Largest Perimeter Triangle - leetcode, C++ version
Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.


Example 1:

Input: nums = [2,1,2]
Output: 5
Example 2:

Input: nums = [1,2,1]
Output: 0 - cannot create a triangle

Example 3:

Input: nums = [2,1,2, 3]
Output: 7, these triangles can be  2 1 2,  2 2 3 , but 2 2 3 is 7 > 5

*/

/*given three numbers and ask whether these number can make a triangle, the answer is that if : sum of any two adges > the last edges -> three numbers can make the triangle. 
In other words, ((nums[i] + nums[i+1]) > nums[i+2]) && ((nums[i+1] + nums[i+2]) > nums[i]) && ((nums[i] + nums[i+2]) > nums[i +1] ))
but what if we sort them? after sorting we can easily see that:
    
    the biggest edges + the smallest edges always > the middle edges 
    the biggest edges + the middle edges absolutely > the smallest edges.

hence we only need to check one condition if the middle edges +  the smallest edges > the biggest edges -> it is a triangle.

Solution: sort the nums 1st then check only 1 condition for each tuple of three

*/
#include<iostream>
class Solution{

public:

    int largestPerimeter(vector<int>& nums){
        
        
        sort(nums.begin(), nums.end()); // sort the vector nums
        /*check the condition to know whether the tuple of theee numbers can be a triangle and we want to get the largest perimeter hence: */
        for(int i = nums.size() -3; i >=0; --i){
            if(nums[i] + nums[i+1] > nums[i+2]){
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }

    return 0;

    }
};
