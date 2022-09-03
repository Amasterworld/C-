/*1985. Find the Kth Largest Integer in the Array
You are given an array of strings nums and an integer k. Each string in nums represents an integer without leading zeros.

Return the string that represents the kth largest integer in nums.

Note: Duplicate numbers should be counted distinctly. For example, if nums is ["1","2","2"], "2" is the first largest integer, "2" is the second-largest integer, and "1" is the third-largest integer.

Example 1:

Input: nums = ["3","6","7","10"], k = 4
Output: "3"
Explanation:
The numbers in nums sorted in non-decreasing order are ["3","6","7","10"].
The 4th largest integer in nums is "3".
Example 2:

Input: nums = ["2","21","12","1"], k = 3
Output: "2"
Explanation:
The numbers in nums sorted in non-decreasing order are ["1","2","12","21"].
The 3rd largest integer in nums is "2".
Example 3:

Input: nums = ["0","0"], k = 2
Output: "0"
Explanation:
The numbers in nums sorted in non-decreasing order are ["0","0"].
The 2nd largest integer in nums is "0".

*/

/*Solution: put all elements from nums to priority_queue, pq, then always get the largest number in the pq, we want to the get the kth then  int new_pq_size = pq.size() - k 
then keep poping until pq.size() == new_pq_size; or put one by one elements to pq whenever pq.size() >k then pop, at the end pq.top() is kth largest value.
the problem is that vector<string>nums, that means nums contain digit in string form hence we must create  a custom comparator to compare two strings 
*/

#include<iostream>
#include<queue>
#include<vector>
#include <cstring>
class Solution{
private:
    struct comparator{

        bool operator()(const std::string& s1, const std::string& s2){
            /*if s1.size() > s2.size(), of course s1 is bigger then s2, if they are the same size hence use strcmp() method to compare*/
            return (s1.size() > s2.size() || (s1.size() == s2.size() && strcmp(s1.c_str(), s2.c_str()) > 0 )); // to_int(s1) > to_int(s2)
        }

    };
public:
    std::string kthLargestNumber(std::vector<std::string>& nums, int k){

        std::priority_queue<std::string, std::vector<std::string>, comparator> pq_num;

        for (auto str_num : nums){
            
            pq_num.emplace(str_num);
            if (pq_num.size() > k){
                pq_num.pop();
            }   
        }
        return pq_num.top();
    }

};

int main(){

    //std::vector<std::string> nums {"3","6","7","10"};
    //std::vector<std::string> nums {"0","0"};
     std::vector<std::string> nums {"0","1","1","1"};
    int k = 1;

    Solution s;
    std::cout<< s.kthLargestNumber(nums, k)<<'\n';
    return 0;

}