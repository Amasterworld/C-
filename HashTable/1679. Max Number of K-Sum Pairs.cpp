//1679. Max Number of K-Sum Pairs

/*
Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.

Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.

*/

/* SOLUTION : many solutions, we can easily see that it is a variant of 2 sums (hash table), we also can sort it and use 2 pointers to check, 
bruten force also can be used here and accepted , 

*/
#include<iostream>
#include<unordered_map>
using std::cout;
using std::endl;
class Solution {
public:
    // with this solution time complexity (TC) only is O(n), n is the number in nums SC: O(n)
    int maxOperations(vector<int>& nums, int k) {
        // to store the frequency of the number in nums for example  <2,3> that means the number 2 appears 3 times in nums
        unordered_map<int, int> u_m;

        int ans = 0;

        for (int curr_num : nums)
        {
            // every time we take 2numbers, one is curr_num, and one is k - curr_num
            int need_num = k - curr_num;
            // if the need_num still exist in the hash table: that means, need_num +curr_num = k --> ans++;
            if (u_m[need_num] > 0 )
            {
                ans++;
                u_m[need_num]--;
            }
            else
            {
                u_m[curr_num]++; // to use it we can avoid  to use for-loop at the beginning of the program
                /*
                for (int num : nums)      for(int i = 0; i < nums.size(); ++i){
                    {                        {
                        u_m[num]++;             u_m[nums[i]]++;
                    }                         }
                                
                
                
                
                to add frequency of the numbers to u_m
                */
                
                 
                // for example nums = [1,2,3,4], curr_num = 1, need_num = 4, but at the 1st iteration um[4] < 0 -> um[1]++ that means  <1,1
                // then at the last iteration: curr_num = 4, need_num = 1, um[1] = 1> 0 -->ans++
                 
            }

        }
        return ans;
        // with this solution time complexity (TC) only is O(n), n is the number in nums SC: O(n)

    }
};
// slow solution TC(nlogn) SC O(1)
class Solution_with_two_pointers
{
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        int ans = 0;
        // sort the nums
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        int l = 0, r = nums.size() -1;
        while (l < r && nums[l] < k)  // pruning:  nums[left] < k
        {
            int mid = l + (r - l)/2;
            
            if (nums[mid] >=k){ 
                r = mid;
                
            }
            if (nums[l] + nums[r] == k)
            {
                ans++;
                l++;r--;
            }
            else if (nums[l] + nums[r] > k)
            {
                r--;
            }
            else if (nums[l] + nums[r] < k)
            {
                l++;
            }
        }
    return ans;
    }
};