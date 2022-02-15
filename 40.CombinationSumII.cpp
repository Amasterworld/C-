/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
*/

/*SOLUTION: think in this way, we should sort the candiates array, and then
e.g1 = [1,1,2,5,6,7,10]
now  1st, target = 8 (for example), then 8 - candidates[0] =
8 - 1 = 7 > 0, add 1 to temp_v, and  update new target = 7, increase idx from 0 to 1, 7 - candidates[1] = 6 > 0
and 1 to temp_v  and keep updating until new_target == 0 ans.emplace_back(temp_v);
or new_target < 0 then break and comeback to previous recursion for poping the last added value into 
the temp_v; --> RECURSION is a solution, note that recursion also can be seen as the depth first search


*/

class Solution{
public:

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        
        
        int m = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp_ans; // or temp_v

        // if the smallest in candidates still  greater than target, hence the ans should be [[]]
        if (candidates[0] > target) return ans;

        
        recur(candidates, ans, temp_ans, target, 0);

    return ans;
    }

    void recur(vector<int>& candidates, vector<int>& ans, vector<int> temp_ans, int target, int idx){
        
        int m = candidates.size();

        if (target == 0){

            ans.emplace_back(temp_ans);
        }

        for (int i = idx; i < m; ++i){

            if (candidates[i] > target){
                break;  // (1)
            }
             // [1,1,2,5,6,7,10], after 1s recursion we got [1,2,5] ->indexes in candidates(0,2,3)
            // now i++(from idx = 0, hence i++ = 0++ == 1) that means we can get once again
            // the combination [1,2,5] -> indecies (1,2,3) 
            // of course, it is not what we want because we need to get unique combination 
            //hence check the below condition:
            if (i == idx || (i > idx && candidates[i] != candidates[i-1])){

                temp_ans.emplace_back(candidates[i]);
                int new_target = target - candidates[i];
                recur(candidates, ans, temp_ans, new_target, i+1);

                // pop the current value in temp_ans if  (1) is satisfied.
                //cout<<"i after breaking = "<<i<<" ";
                temp_ans.pop_back();

            }
        }

    }


};