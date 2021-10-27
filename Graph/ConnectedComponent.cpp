#include <iostream>
#include <vector>
#include <queue> //FIFO
#include <cstring>  // for memset
using namespace std;

const int n = 5;
const int m = 5;
 
// agent can move up down, back and forward
int dx[] = {0,1,-1,0};  // 0 up, 1 forward, -1 backward, 0 down
int dy[] = {1,0,0,-1};
// to check whether visited or not
int visited[n][m];

// checkwhether the cell is visited
bool isVisited(int x_agent, int y_agent, int matrix[n][m]){

    if (x_agent < n and y_agent < m and x_agent >= 0 and y_agent >= 0){
        if (visited[x_agent][y_agent] == false and matrix[x_agent][y_agent] == 1) return true; //
        else return false;

    }
    else return false;
}    
int count = 0;

void ConnectedComponent(int matrix[n][m]){
     
     // to check every cells
     for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (visited[i][j] == false and  matrix[i][j] == 1){
                
                  // store i and j
                  queue<pair<int, int> > q;
                  q.push({i, j});
                  visited[i][j] = true;

                while (!q.empty()){
                    pair <int, int> temp = q.front();
                    q.pop();
                    int x = temp.first; int y = temp.second;
                    for (int i = 0; i< 4; ++i){     // number 4 because the agent only can move up down, left and right.
                        int newX =   x +  dx[i];
                        int newY =   y +  dy[i];
                        if(isVisited(newX, newY, matrix)){
                            
                            visited[newX][newY] = true;
                            q.push({newX, newY});
 
                        }  

                    }
                }

                count += 1;

            }
                

                


           


        }       
    }
    cout <<count <<endl;
}

 int main()
{
    // Given input array of 1s and 0s
   /* int matrix[n][m]
        = { { 1, 1, 1, 1, 1, 1 }, 
            { 1, 1, 0, 0, 0, 0 },
            { 0, 0, 0, 1, 1, 1 }, 
            { 0, 0, 0, 1, 1, 1 },
            { 0, 0, 1, 0, 0, 0 }, 
            { 1, 0, 0, 0, 0, 0 } }; */

    int matrix[n][m] ={{0, 1, 0, 1, 0},
                       {0, 1, 0, 1, 0},
                       {0, 1, 1, 1, 0},
                       {0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0}};
 
    // queries array
    //int queries[] = { 6, 1, 8, 2 };
 
    // sizeof queries array
    //int N = sizeof(queries) / sizeof(queries[0]);
 
    // Initialize all cells unvisited, ptr(visited) Pointer to the block of memory to fill.
    // , value (false) - Value to be set. The value is passed as an bool(also can be another type)
    //, num (Number of bytes to be set to the value.

    memset(visited, false, sizeof visited);
 
    // Count the frequency of each connected component
    ConnectedComponent(matrix);
 
    // Iterate over the given queries array and
    // And answer the queries
   
    
 
    return 0;
}