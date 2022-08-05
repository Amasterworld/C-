
/*329.Longest Increasing Path in a Matrix - leetcode

Given an m x n integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. 
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

Example 1:

Input: matrix = ^ [[9,9,4],
                |  [6,6,8],
                |  [2,1,1]]
                |< - -
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9] by the arrow above.
Example 2:
                  ------->
Input: matrix = [[3,4,5],|
                 [3,2,6],
                 [2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1

SOLUTION: this problem is more or less the same problem 1219, PathWithMaximumGold. 
it is hard problem, maybe, to solve it, we should combine two algorithm : dfs  + dynamic programming
    Time complexity: O(m*n)
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
class Solution {
private:
    int memo[201][201];
    //vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    constexpr static int dir = 4;
    int dx[dir] = {0, 1, -1,  0};
    int dy[dir] = {1, 0,  0, -1};
    bool isValid(int m, int n, int x, int y, std::vector<std::vector<int>> &vis, std::vector<std::vector<int>>& matrix, int val_curr_cell){
        
        return (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && matrix[x][y] > val_curr_cell);
          
    }
    
    int dfs(std::vector<std::vector<int>>& matrix, int x, int y, std::vector<std::vector<int>>& vis){
        
        int temp = 0;
        int m = vis.size();
        int n = vis[0].size();

        if(memo[x][y] != -1){
            return memo[x][y];
        }
        int val_curr_cell = matrix[x][y];
        for(int i = 0; i < dir; ++i){

            int new_x =  x + dx[i];
            int new_y =  y + dy[i];
            /* the next valid cells must be in the grid and the value in these cells should > val_curr_cell */
            if(isValid(m, n, new_x, new_y, vis, matrix, val_curr_cell)){
                //  each valid point should mark visited 
                vis[new_x][new_y] = 1;
                temp = std::max(temp, 1 + dfs(matrix, new_x, new_y, vis));
                // and also mark unvisited after passing it
                vis[new_x][new_y] = 0;
            }
        }
        return (memo[x][y] = temp);
    }
public:
    
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        // memo or dp array (or vector) used to store the ans of each path
        memset(memo,-1,sizeof(memo));
        // vis array (or vector) used to store the path from initial point with the corresponding i and j
        // and the path is reset after each path
        std::vector<std::vector<int>> vis(m,std::vector<int>(n,0));
        int ans = 0;

        //from P(i = 0, j = 0) -> to (0,1) ->..., we get one ans, e.g. ans = 2, but this ans maybe is not final answer, the final answer can be from P(0,0)
        //-> (1,0)->.... then we should reset the initial point after each time we get ans
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // update this point is visited
                vis[i][j] = 1;
                //get ans,  but maybe this ans is not the final ans 
                ans = std::max(ans, 1 + dfs(matrix, i, j, vis)); // 1+ dps, because,  we always have at least 1 cell to go
                // then, should reset vis[i][j] after get ans
                vis[i][j] = 0;
            }
        }
        return ans;
    }
};

int main(){
    std::vector<std::vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    Solution s;
    std:: cout<<s.longestIncreasingPath(matrix);

}
