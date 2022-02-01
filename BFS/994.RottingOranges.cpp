/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

*/
/* SOLUTION: BDS needs to use but we have MULTI source here, fore example gird = {{}}

*/



#include <iostream>
#include <vector>
#include <queue> //FIFO
#include <cstring>  // for memset
using namespace std;


class Solution{
public:
    bool is_valid(int x, int y, vector<vector<int>>& grid){ // & is importante, without it, when grid is big, the program can run slowly

        int m = grid.size(), n = grid[0].size();
        return (x >= 0 && x < m && y >=0 && y < n);
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int dx[4] = {0,1,-1, 0};
        int dy[4] = {1,0, 0,-1};

        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int> > q, q_n;
        // get all rotten oranges at 0 minutes
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 2){
                    q.push({i,j});

                }
            }
        }
        int time = 0;
        while (!q.empty() || !q_n.empty()){
            // search all possible frest oranges can be rotten from 0 to 1 mins
            while (!q.empty()){
                
                pair<int, int> temp_q = q.front(); // q.front(), stack is s.top()
                q.pop();
                // check all possible rotten orange from the original rotten oranges
                for (int i = 0; i < 4; ++i){

                    int new_x = temp_q.first  + dx[i];
                    int new_y = temp_q.second + dy[i];
                    if (is_valid(new_x, new_y, grid) and grid[new_x][new_y] == 1){

                        grid[new_x][new_y] = 2;
                        q_n.push({new_x, new_y});

                    }

                }
            
            }
            // when this while loop finishes the mean all rotten oranges for the  1 mins are checked and stored in q_n
            // now assign them to the q and reset q_n
            queue<pair<int, int> > temp;
            q = q_n;
            q_n = temp; // reset q_n
            // now if q is not empty that means the time can be >= 1
            // because grid can contain  rotten oranges but 0 fresh orange, nothing to be rotten at 1 -> q_n is empty -> q is empty
            if (!q.empty()) time++;

        }

    // now if still remains any fresh oranges in the grid, that means they never can be rotten (they are isloted)
     for ( int i = 0; i < m; ++i){
         for ( int j = 0; j < n; ++j){

             if (grid[i][j] == 1) return -1;
         }
     }

    return time;

    }
    

};





int main(){

        vector<vector<int>> grid = { {2,1,1}, {0,1,1}, {1,0,1} };
        Solution solu;
        cout<< solu.orangesRotting(grid);



    return 0;
}