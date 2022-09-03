/*967. Numbers With Same Consecutive Differences
Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.

Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.

You may return the answer in any order.

Example 1:

Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.

Example 2:

Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

*/

/*SOLUTION: use recursion (DFS) to build up the number step by step until its length  == n then add the ans vector and return

for example: Input: n = 3, k = 7, first we check i = 1 (not 0) so we have 1x, and keep searching x from 0 to 9, if abs(x - 1) == k then add x
x == 8, hence we have 18, 18 lenght is 2 < 3(n) then keep recursing 18x and if (8 -x) == k, x == 1 add, hen we have 181, 
181 length is 3 == n, add to ans vector ans return.

TC: n*(2^n) in worst case,  0<= n <=9 . 
SC: O(n) - we use one matrix to store the results.
*/
#include<iostream>
#include<vector>

class Solution{

    void search_num(int i, int n, int k, std::vector<int>& ans){
        /*based condition*/
        if(std::to_string(i).size() == n){
            ans.emplace_back(i);
            return;
        }
        
        /*keep searching the numbers that are satisfied abs(last_number of i - j) == k */
        for(int j = 0; j < 10; ++j){
            int last_num = i % 10; // if i == 18 we should get 8
            if (abs(last_num - j) ==k){
                /*if we found j hence add it at the end to i and keep searching*/
                search_num(i*10 + j, n, k, ans);
            }
        }

    }
public:


    std::vector<int> numsSameConsecDiff(int n, int k) {
        std::vector<int> ans{};

        for(int i = 1; i < 10; ++i){
            search_num(i, n, k, ans);
        }
        return ans;
    }
};

int main(){
    int n = 3, k = 7;
    std::vector<int> ans{};
    Solution s;
    ans = s.numsSameConsecDiff(3, 7);
    for(auto ele : ans){
        std::cout<<ele<<" ";
    }

    return 0;
}