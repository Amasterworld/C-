/*Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
 You may assume that the majority element always exists in the array.

 Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

/*SOLUTION: use map to store the number and its frequency
but it take O(n) time complexity (TC)

we can use another solution 0(1) TC think in that way: majority element > n/2
that means if we count it it should > n/2 but the problem is we do not know which number is 
majority for counting, to solve that matter, we  assign the 1st element when count ==0
if we meet it again count ++, otherwise coun-- (1) if cound ==0 again, we assign to the current number
and repeat (1), at the end, because the majority element > n/2 that means count never can be 0 
then this number is the result

*/
//approach 1 using map 

class Solution {
public:
    int majorityElement(vector<int>& nums){

        map <int, int> mp;
        int n = nums.size();
        for (int num : nums){
            mp[num]++;
            if (mp[num] > n/2)  return num;
        }

        return -1;


    }

};
// approach 2 O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums){

        int count = 0, res, n = nums.size();

        for (int i = 0; i < n; ++i){
            // assing 1st element and check its frequency

            if (count == 0){ // (1)

                res = nums[i];
            }
            // whenver we meet the number != res coun--
            if(res != nums[i]){count--};
            // whenever we meet the same number with res increase count
            else if (res == nums[i]) count++;

        }
        // at the end majority element > n/2, that means (1) never is satisfied again the res is 
        // the majority element
        return res;

    }

};