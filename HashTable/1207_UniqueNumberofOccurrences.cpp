/*1207. Unique Number of Occurrences
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, 
or false otherwise. 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false, because 1 appears 1 time, 2 also 1 time, so their appearence are not unique
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
*/

/*SOLUTION: hashtable is very nice problem for this problem, first count the frequencies of the number in vector arr
then we transfer their frequency to unordered_set, if at the end the size of set == size of frequencies -> return true
otherwise return false
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
class Solution{

public:
    bool uniqueOccurrences(std::vector<int>& arr) {

        std::unordered_map<int, int>freq_num; // count frequencies of num in arr
        std::unordered_set<int>set_freq; // 

        for(const auto& num : arr){
            freq_num[num]++;
        }

        for(const auto& [num, freq] : freq_num){
            set_freq.insert(freq);
        }
        if(set_freq.size() == freq_num.size()){
            return true;
        }
        return false;
    }
};

int main(){
    
    std::vector<int> arr = {1,2,2,1,1,3};
    Solution *ptr = new Solution();
    std::cout<<ptr->uniqueOccurrences(arr)<<'\n';
    delete ptr;
}