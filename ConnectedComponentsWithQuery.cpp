/*
find the connected components in a matrix 2d
and then answer the number of each conneted component. for example :
int M[][COL] = {     { 1, 1, 0, 1, 1 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 1, 0, 0, 1 } };

qurey = [1 ,2 ,3 ,4 ,5 ]
output: 5 and  3-2 (1 connected components with 3 members = 1x3, 1x5, 2x1, 1x2, 0x4  ) based on the query array
*/


#include <iostream>
#include <vector>
#include <queue> //FIFO
#include <cstring>  // for memset
#include <unordered_map>

using namespace std; 
const int m = 5;
const int n = 5;

// check whether the agent has visited the cells
int visited[m][n];

// movement of the agent 
const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0,  0, -1};

bool is_visited(int x, int y, int mat[m][n]){
    if (0 <= x and y >= 0 and x < m and y < n){
        if (visited[x][y] == false and mat[x][y] == 1) return true;
        else return false;
    }
    else return false;

    

}
int COUNT = 0;
unordered_map <int, int> match_query;
void FindConnectedComponents(int mat[m][n]){
    
    // check every unvisited cell in the mat
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){

            if (visited[i][j] == false and mat[i][j] == 1){
                queue<pair<int, int> >q;
                //store coord of 1 
                q.push({i,j});  // now q is not empty
                // update visited
                visited[i][j] = true;

                COUNT = 0; // reset count after finding a new number 1

                while (!q.empty()){
                    pair<int, int> temp_q = q.front();  //  q is queue (FIFO) hen 
                    q.pop();  // now we can delete value of q at top

                    int x = temp_q.first; int y = temp_q.second;
                    COUNT+=1;
                    
                    // check adjust cells from i and j (now they are temp_q.first temp_q.second ) make mat[i]][j] == 1
                    for (int i = 0; i < 4; ++i){  // number 4 because agent only can move UP DOWN LEF AND RIGHT
                        
                        int newX = x + dx[i];
                        int newY = y + dy[i];
                        if (is_visited(newX, newY, mat)){

                            visited[newX][newY] = true;
                            // continue store newX and newY on q to keep checking
                            q.push({newX, newY});

                        }

                    }

                }
            cout << COUNT <<" ";
            match_query[COUNT]++; // like we store a letter (a) and count how many letter "a" in a given sentence.
            }


        }

    }
   
}

int main(){

int mat[m][n] =   {  { 1, 1, 0, 1, 1 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 1, 0, 0, 1 } };

const int query[] = {1, 2, 3,4, 5 };
int N = sizeof(query) / sizeof(query[0]);
cout <<"N = "<<N<<endl;
// set all cells in visited are false



memset(visited, false, sizeof visited);

FindConnectedComponents(mat);
cout<< endl;
for (int i = 0; i < N; ++i){
    cout <<match_query[query[i]]<<"x"<<query[i] << " ";


}


return 0;
}






