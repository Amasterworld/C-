/* find all connected components in a matrix 2D. Connected components are the number 1 that connect together. if only one number 1 is around the number 0. it also is counted as one connected components

for example Matrix = {{1, ,1 ,1 ,1, 1, 1}
                      {1, ,1 ,0 ,0, 0, 0}         
                      {0, ,0 ,0 ,0, 0, 0} 
                      {0, ,0 ,1 ,1, 0, 1}
                      {0, ,0 ,1 ,1, 0, 0}
                      {1, ,0 ,0 ,0, 0, 1}}

should return 5

*/


/* SOLUTION: use graph to solve this problem, 


*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // for memset
using namespace std;
const int n = 6; // given the  size of a matrix n x m
const int m = 6;

const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};
 
 // create a visited array to check whether the cells are visited or not

int visited[n][m];
//check whether our agent's coors are satisfied,
// and check the next movement where it is visited

bool is_visited(int x, int y, int matrix[n][m]){
    if (x < n and y< m and x >= 0 and y >= 0){
        if (matrix[x][y] ==1 and visited[x][y] == false)
            return true;
        else 
            return false;
    
    }
    else
        return false;

}
// we only need to cout, no need return any value so void function is enough
int count = 0;
void  FindConnectedComponent(int matrix[n][m]){

// search every cell in the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j){
            if (visited[i][j] == false and matrix[i][j] == 1){
                
                visited[i][j] = true;
                // store i and j to check the next adjust cells
                // to store i and j we can use ordered_map or queue FIFO
                queue<pair<int, int> > q;
                q.push({i, j});
                
                
                while (!q.empty()){
                    pair <int, int> temp_q = q.front();
                    q.pop();
                    int x = temp_q.first, y = temp_q.second;
                    for (int i = 0; i < 4; ++i){  // number 4 because our agent only can move  UP DOWN LEFT AND RIGHT
                        // after this 4 all number 1 around i and j are stored at q
                        int newX = x + dx[i]; // dx is the possible movement of agent in a grid (for this case is right and left)
                        int newY = y + dy[i]; // dy is the possible movement of agent in a grid (for this case is UP and DOWN

                        if (is_visited(newX, newY, matrix)){
                            
                            visited[newX][newY] = true;
                            q.push({newX, newY});


                        }


                    }
                }
                count +=1;
            }



        }


    }
}





int main(){

int matrix[n][m] =      { { 1, 1, 1, 1,  1, 1},
                        { 1, 1, 0, 0,  0, 0},         
                        { 0, 0, 0, 0,  0, 0}, 
                        { 0, 0, 1, 1,  0, 1},
                        { 0, 0, 1, 1,  0, 0},
                        { 1, 0, 0, 0,  0, 1} };

    // set all visited array is false
    memset(visited, false, sizeof visited);

    FindConnectedComponent(matrix);

    return 0;
}