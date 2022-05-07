/*
Given an array of n integers nums, a 132 pattern is a subsequence of three 
integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

*/

/*

SOLUTION: Firstly, Brute force: easy to do 3 for loops. TC:O(n^3), SC: O(1) 
for (int i = 0; i < nums.size(); i++) {
    for (int j = i+1; j < nums.size(); j++) {
        for (int k = j+1; k < nums.size(); k++) {
            if (nums[i] < nums[k] && nums[k] < nums[j]) {
                return true;
            }
        }
}
    return false;

Second, use two pointers: now we can do 2 for loops. TC:O(n^2), SC:O(1)
in the three numbers, nums[i], nums[j] and nums[k], nums[i] always should be the minimum of 3
therefore we should update it with the 2 number to get the min between them after each comperation 
for example  nums [3, 1, 4, 2], 1st int min_3 = nums[0]
then: use 2 for lopps and {if nums[k] < nums[j] && nums[k] > min_3} return true;
else: 
min_3 = min(nums[j], nums[k]); 
to update the min_3 
WHY? because: after comparning (by if) and it is false what we need to update
min_3 is 1 not 4 even nums = [3, 4, 1, 2] 
because if min_3 update to 4, after that is 1 it is USELESS,  because 4 > 1 even the next one is whatever the number, so they cannot be 132
thefore get the smallest of 2


Last solution: we implemnt below TC: O(n) and SC: O(n) (using stack)

first solution we use 3 pointers, second solution we use 2 pointers, then last solution we use  only 1 pointer   
how to that? we should use stack to help us,
we take an example nums = [3,5,3,4,2,3,7] to explain:

third _val = INT_MIN,  stack = [7] because st is empty,  then add 3 --> st = [3,7] because nums[i] = 3 < st.top() = 7
sthen st = [2,3,7] then nums[i] = 4, 4 > 2, has a  hope to be 132, update third_val = st.top() =2
but to get the best chance to have 132 we should get the biggest possible number in the stack, 
but this number must be smaller than nums[i]. WHY? because current nums[i] is nums[j], nums[k] is
now is third_val, hence nums[i] is the next i of for loop, to have 132 it should smallers than third_val, thefore if the third_val can be get bigger,so nums[i] in the for loop, has more space to be smaller than third_val --> return true
thefore we make a while loop, until !st.empty and nums[i] > st.top()
update : third_val = st.top(); st.pop();

from out example: nums[i] = 4 >  st.top() = 2 , while loop, third_val = 2, st.pop();
and then nums[i] = 4 > st.top() = 3 , while loop, third_val = 3, st.pop();, nums[i] = 4 < st.top() = 7 . stop while loop , add nums[i] to stack, st = [4,7] and check next nums[i] =3 = third_val, add, stack = [3,4,7], nums[i] = 5, keep doing the same we get third_val = 4, check next nums [i] = 3 < third_val = 4, return true

with this solution, we do not lose the cases.

*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
     
        int third_val = INT_MIN; 
        stack<int> st;
        if (nums.size() <=2) return false;
        for (int i = nums.size()-1; i >= 0; i--) 
        {
            if (nums[i] < third_val) // it will nums[k]
            {
                return true;
            }
            // nums = [3, 6, 4, 1, 2]
            while(!st.empty() && nums[i] > st.top())
            {
                //nums at current i is nums[j] >  st.top() is nums[k],
                // that means if nums [j] >  nums[k] update third_val 
                third_val = st.top();// get max we do not need to st.pop() because we only need to 
               // cout<<"third_val "<<third_val<<"  "<< nums[i]<<endl;
                st.pop();
            }
            st.emplace(nums[i]);

        } 
        //nums = [3,5,3,4,2,3,7], st = [7] -> st = [3,7] -> st = [2,3,7], nums[i] = 4 > st.top() = 2
        // has hope to be 132, third_val = 2 but to get the best chance get need to get the number as close as nums[i] =4-> while loop, third_val = 3 > 2 and  3< 4, stack takes2, pop 2, takes 3, pop 3, 7 > 4 stop, add nums[i] = 4, hence st =[4,7], nums[i] = 3 == third_val, and < st.top(), st = [3,4,7]        , nums[i] = 5 > third_val, and > st.top(), third_val = stop() = 3, like b4 get the best chance hence third_val = 4. nums[i] = 3  < third_val -> return true  
        
    return false;
    }
    
};

