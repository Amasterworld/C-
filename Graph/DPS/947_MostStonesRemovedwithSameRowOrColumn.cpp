/*
947. Most Stones Removed with Same Row or Column - leetcode
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
*/

/*SOLUTION: we can  use DFS for each stone and then count the connected stones and compare the reuslt 
to find the maximum number stones can be removed. But it is a bit slow because we must reset
visited vector for each set of a stone. and compare

->  another solution: still using DFS and count the sum of possible linked stones, for example: sum_island
then size_stones - sum_island = maximum removed stones;
for example we have  stones array with size 6 (that mean we have 6 stones) and all of the
are linked together by above rules. hence maximum nnumber of stones can be removed is  6 -1 = 5
because the last stone cannot be removed. So what if we have 5 linked stones, and 1 is not linked to others
hence max_rem_stones = 6 - 2 = 4. what if all 6 stones are not linked together hence 
max_rem_stones = 6 - 6 = 0;

Now the problem is very simple: we want to count all island connected by above rule -> 
come back to the problem 200(Number of Island). When we get it we only need to - this number and DONE
*/
#include<iostream>
#include<vector>
class Solution{

private:

    bool is_linked(const std::vector<int>& coord_stone1, const std::vector<int>& coord_stone2){
        if(coord_stone1[0] == coord_stone2[0] || coord_stone1[1] == coord_stone2[1]){
            return true;
        }
        return false;
    }
    void dfs(std::vector<std::vector<int>>& stones, std::vector<bool>& visited, int curr_idx){
        /*update visited*/
        visited[curr_idx] = true;
        
        for(int i = 0; i < stones.size(); ++i){
            if(visited[i]){
                continue;
            }
            /*if the stone[curr_idx] linked with stone[i] then keep searching and mark
            it or them visited
            */
            if(is_linked(stones[curr_idx], stones[i])){
                dfs(stones, visited, i);
            }
        }

    }

public:
    int removeStones(std::vector<std::vector<int>>& stones){

        int size_stones = stones.size();
        int sum_islands = 0; // an island is a linked stones
        std::vector<bool> visited(size_stones, false);

        for(int i = 0; i < size_stones; ++i){
            if(visited[i]){
                continue;
            }
            dfs(stones, visited, i);
            sum_islands++;
        }
    return (size_stones - sum_islands);
    }
    
};

int main(){
    std::vector<std::vector<int>> stones ={{0,0}, {0,1}, {1,0}, {1,2}, {2,1}, {2,2}};
    Solution s;
    std::cout<<"the maximum stones that can be removed are " <<s.removeStones(stones)<<'\n'; //output 5
    std::vector<std::vector<int>> stones_1 ={{0,0}, {0,2}, {1,1}, {2,0}, {2,2}}; // (1,1) does not connect to any stones
    std::cout<<"the maximum stones that can be removed are " <<s.removeStones(stones_1)<<'\n'; //output 5
    return 0;
}

