/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
*/

/*SOLUTION: like major element I, map can be used here but O(n) how to get O(1)?
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        map <int, int> mp;
        int n = nums.size();
        for (int num: nums){
            
            mp[num]++;
            
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            
            if (it->second > n/3){
                ans.emplace_back(it->first);
                cout<<it->first<<" ";
            }
        }
        
    return ans;
    }
};