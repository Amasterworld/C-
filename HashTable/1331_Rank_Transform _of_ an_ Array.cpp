/*Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

    Rank is an integer starting from 1.
    The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
    Rank should be as small as possible.

 

Example 1:

Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.

Example 2:

Input: arr = [100,100,100]
Output: [1,1,1]
Explanation: Same elements share the same rank.

Example 3:

Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]
*/

/*SOLUTION: we create a sorted_arr copying original vector arr, then sort sorted_arr, after sorting, it can easily see that the elementnd 
and its index +1 that is its rank, except for the same elements, example 1 after sorting is 10, 20, 30, 40, 10 is rank 1, 20 is rank 2 and so on
what if they are 10, 10, 20, 20, 30 , 40, we want to get 10, 10 rank 1, 20, 20 rank 2, 30 rank 3, 40 rank 4. To do it we tranfer them in unordered_map <elem, rank>
if the ele are the same, then continue (rank does not change), otherwise u_m[sorted[i]] = rank++;
*/

class Solution{
  
    std::vector<int> arrayRankTransform(std::vector<int>& arr){
        
        vector<int>sorted_arr;
        int arrSize = arr.size();
        
        sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        unordered_map<int, int> ele_rank_mp;
        int rank = 1;
        /*transfer elements in sorted_vec to unordered_map if elements are the same hence their rank does not change*/
        
        for(int i = 0; i < sorted_arr.size(); ++i){
            
        /*if sorted_arr[i] is present in the ele_rank_mp then its rank does not change*/
            if(ele_rank_mp[sorted_arr[i]]) continue;
            ele_rank_mp[sorted_arr[i]] = rank++;
        }
        /*replace their values by their rank */
        for(int i = 0; i < arrSize; ++i){
            
            arr[i] = ele_rank_mp[arrp[i]];
        }
        return arr;
    }
    
}; 
