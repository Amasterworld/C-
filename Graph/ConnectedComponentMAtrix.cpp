#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <queue>
using namespace std;
 
const int n = 6;
const int m = 6;

// there are set up 4 direction (if use digonal then can be 8) where I can move in from any position in gird 
const int dx[] = { 0, 1, -1, 0 };   // dx that mean move forward and backward
const int dy[] = { 1, 0, 0, -1 };  // dy where == 1 that mean move up and down
 
// stores information about  which cell
// are already visited in a particular BFS
int visited[n][m];
 
 
// Stores the count of cells in
// the largest connected component
int COUNT;
 
// Function checks if a cell is valid, i.e.
// it is inside the grid and equal to 1
bool is_valid(int x, int y, int matrix[n][m])
{
    if (x < n && y < m && x >= 0 && y >= 0) {
        if (visited[x][y] == false
            && matrix[x][y] == 1)
            return true;
        else
            return false;
    }
    else
        return false;
}
 
// Map to count the frequency of
// each connected component
map<int, int> mp;
 
// function to calculate the
// largest connected component
void findComponentSize(int matrix[n][m])
{
    // Iterate over every cell
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
 
            if (!visited[i][j] && matrix[i][j] == 1) {
                COUNT = 0;
 
                // Stores the indices of the matrix cells
                queue<pair<int, int> > q;
 
                // Mark the starting cell as visited
                // and push it into the queue
                q.push({ i, j });
                visited[i][j] = true;
 
                // Iterate while the queue
                // is not empty
                while (!q.empty()) {
 
                    pair<int, int> p = q.front();
                    q.pop();
                    int x = p.first, y = p.second;
                    COUNT++;
 
                    // Go to the adjacent cells
                    for (int i = 0; i < 4; i++) {
 
                        int newX = x + dx[i];
                        int newY = y + dy[i];
 
                        if (is_valid(newX, newY, matrix)) {
                            q.push({ newX, newY });
                            visited[newX][newY] = true;
                        }
                    }
                }
 
                mp[COUNT]++;
            }
        }
    }
}
// Drivers Code
int main()
{
    // Given input array of 1s and 0s
    int matrix[n][m]
        = { { 1, 1, 1, 1, 1, 1 }, 
            { 1, 1, 0, 0, 0, 0 },
            { 0, 0, 0, 1, 1, 1 }, 
            { 0, 0, 0, 1, 1, 1 },
            { 0, 0, 1, 0, 0, 0 }, 
            { 1, 0, 0, 0, 0, 0 } };
 
    // queries array
    int queries[] = { 6, 1, 8, 2 };
 
    // sizeof queries array
    int N = sizeof(queries) / sizeof(queries[0]);
 
    // Initialize all cells unvisited, ptr(visited) Pointer to the block of memory to fill.
    // , value (false) - Value to be set. The value is passed as an bool(also can be another type)
    //, num (Number of bytes to be set to the value.

    memset(visited, false, sizeof visited);
 
    // Count the frequency of each connected component
    findComponentSize(matrix);
 
    // Iterate over the given queries array and
    // And answer the queries
   
    for (int i = 0; i < N; i++)
        cout << mp[queries[i]] << " ";

    int sum = 0;
    for (int i = 0; i < mp.size(); i++)
        {
        cout <<mp[i]<<" ";
            
        sum += mp[i];
        }
    cout << "sum = "<< sum << " ";    
 
    return 0;
}