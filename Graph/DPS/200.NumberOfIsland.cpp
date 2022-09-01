/*200.number of island
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all 
four edges of the grid are all surrounded by water.

*/
/*
SOLUTION: BFS or DFS can solve this problem easily.
DFS.
*/

#include<iostream>
#include<vector>

class Solution{
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
public:

    void dfs(std::vector<std::vector<char>>& grid, int i, int j, int rows, int cols){

        /*base condition, i, j should be correct coord and grid[i][j] != 0*/
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] =='0')
            return;
        /*visited*/
        grid[i][j] = '0';

        /*check the neighbour of the cell, grid[i][j] with 4 dirs */
        for(int k = 0; k < 4; ++k){
            int n_i = i + dx[k];
            int n_j = j + dy[k];
            dfs(grid, n_i, n_j, rows, cols);
        }
    }


     int numIslands(std::vector<std::vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        int count  = 0;

        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                
                if (grid[i][j] == '1'){
                    count++;
                    dfs(grid, i, j, rows, cols);
                }

            }

        }

    return count;
    }

};

int main(){
    std::vector<std::vector<char>> grid = {
                                        {'1','1','1','1', '0'},
                                        {'1','1','0','1','0'},
                                        {'1','1','0','0','0'},
                                        {'0','0','0','0','0'}
                                        };
        
    Solution s;
    std::cout<<s.numIslands(grid)<<'\n';
    return 0;
}