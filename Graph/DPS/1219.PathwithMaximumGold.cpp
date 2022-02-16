/*
In a gold mine grid of size m x n, each cell in this mine has an integer representing 
the amount of gold in that cell, 0 if it is empty.
Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.

Example 1:
Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0,0],
 [5,8,7,0],
 [0,9,0,0]
 [0,1,0,0]
 ]
Path to get the maximum gold, 9 -> 8 -> 7.
Example 2:

Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.

*/

/*SOLUTION: 
think in this way: - from given info, we must traveser all cells of grid, 
whenver we meets the cell !=0 then 
calculate all possible gold that we can loot from that cell ->to all possible paths -> Depth First Search. we can get many results ( from different sources !=0)
we only need to maximum gold hence res = max(res, dfs);

cannot visit the same cell more than once, should use visited array or
if we want to save SC then store grid[i][j] to somewhere change the grid[i][j] = something else, 
then return somewhere to grid[i][j] b4 each time the recursion finises.

- from each source we have many possible paths, then we also need to get max loot of each source, ans = max(ans, dfs) (*),
from each cell we have 4 directions to go, to get the max possible loot on each path we need to use the greedy algorithm
whenever we meets the dead end cell, then return it to ans in(*) and compare with the loot from other directions. 

*/

class Solution{
public:

    int getMaximumGold(vector<vector<int>>& grid) {

         //  check whether the cell is 0
        int m  = grid.size();
        int n = grid[0].size();
        int res = 0;
         for ( int i = 0; i < m; ++i){
            for ( int j = 0; j < m; ++j){
                if (grid[i][j] !=0){
                    int max_gold_fr_i2j = dfs(grid, i,j);
                    // we need get max loot gold from all possible sources( each source is where grid[i][j] != 0 ) 
                    res = max(res, max_gold_fr_i2j);

                }

            }


        }


    return res;
    }
    bool is_valid(vector<vector<int>>& grid, int x, int y){
        int m = grid.size();
        int n = grid[0].size();

        return (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0);


    }

    int dfs(vector<vector<int>>& grid, int i, int j){
        int dx[4] = {0,1,-1,0};
        int dy[4] = {1,0,0,-1};
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        // save the value from grid[i][j] != 0
        int temp_val = grid[i][j];
        ans  = 0;
        int max_loot_branch = 0;
        // chage value at grid[i][j] = 0 to avoid visit it again
        grid[i][j] = 0;
        for (int a = 0; a < 4; ++a){
            int new_x = i + dx[a];
            int new_y = j + dy[a];

            if (is_valid(grid, new_x, new_y)){
                // ans = 0 +temp_val and then keep comparing with another values
                // that are taken from dfs(grid, new_x, new_y)
                // in the example 1: when meets 7(dead end point) and ans = 7, ans = max(7, dfs)
                // a increase from 0 to 1, if new_x, new_y is valid then ans = max(7, dfs(grid,new_x, new_y)), once again whenver meets
                // the new dead end for example 1(from 9->1), similarly, return 1 to (1) ans  = max (ans, 1), ans =1(because ans was 0 in this layer) 
                //  from 9 cannot go anywhere except to 1(visited) then return ann(1) +temp_val(9 ) = 10, return 10 to (1)
                // and in this layers ans is 7, now ans = max(ans, 10), 10 > 7 then ans = 10
                // a increase from 1 to 2, new_x = 2, new_y = 0, grid[new_x][new_y] = 5 is valid then dfs again
                // whenever this brand is finished and sum all of the value, then compare again with ans = 10.
                ans = max(ans, dfs(grid, new_x, new_y)); //(1)
            }


        }
        // whenever meets the dead end (1) cannot call itself, then return grid[dead_end_x][dead_end_y] 
        grid[i][j] = temp_val;
    // ans = 0 + temp_val, return to (1)
    return ans + temp_val;
    }

};