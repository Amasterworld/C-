/*
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated 
to another number in the set, which results in repetition of one number and loss of another number.
You are given an integer array nums representing the data status of this set after the error.
Find the number that occurs twice and the number that is missing and return them in the form of an array.


Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:

Input: nums = [1,1]
Output: [1,2]
*/

/* SOLUTION: if we use sort to detect which the number is repeatable, TC is O(nlogn) it is not good solution
instead we can use hash table to store num in nums and use count() or find() method to detect which the number is repeatable, now we need to find which number is missing.
One of the best solution to find the missing number when they are a set from 1 to n is that: using the formula  sum = n(n+1)/2
then calculate the sum from the given nums:  int curr_sum = std::accumulate(nums.begin(), nums.end(), 0); then int miss_num = sum = curr_sum;


*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> freq_int;
        vector<int> ans;
        int n = nums.size();
        
        int sum_full_nums = n*(n+1)/2;
        int sum_current_nums = std::accumulate(nums.begin(), nums.end(), 0);
        for(auto num: nums){
            
            if (freq_int.count(num) >= 1){
                //std::cout<<"num "<<num<<std::endl;
                   ans.emplace_back(num); 
                ans.emplace_back(sum_full_nums- sum_current_nums+num);
                return ans;
            }
            freq_int[num]++;
        }
       
        return ans;
    }
};
