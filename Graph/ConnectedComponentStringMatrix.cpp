#include <iostream>
#include <vector>
#include <queue> //FIFO
#include <cstring>  // for memset
#include<windows.h>
using namespace std;

const int n = 2;
const int m = 4;

int visited[n][m];

const int dx[] = {0, 1, -1, 0}; 
const int dy[] = {1, 0, 0, -1}; 

bool is_visited(int x, int y, string inPut[], char c){

    if (x>=0 and y>=0 and x < n and y < m){
        if (visited[x][y] == false and inPut[x][y] ==c){
            
            return true;
        }
        else return false;

    }
    else return false;


}
int COUNT = 0;
void connectedComponentString(string inPut[]){

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (visited[i][j] == false){
                char c = inPut[i][j]; // save the char that is not visited
               // cout << "char = "<< c<< endl;  
                
            
                queue<pair<int, int> > q;
                q.push({i,j});
                visited[i][j] = true;
               
                
                while (!q.empty()){
                    pair<int, int> temp_q = q.front();
                    q.pop();
                    //cout << q.empty();
                    int x = temp_q.first; int  y = temp_q.second;
                   
                    //Sleep(5000);
                    for (int i = 0; i<4; ++i){
                        int newX =   x +  dx[i];
                        int newY =   y +  dy[i];
                        //cout << "newYX = " <<newY<<" "<<newX<<" "<<inPut[newX][newY] <<endl;
                        
                             

                        if (is_visited(newX, newY, inPut, c)){
                           
                            
                            visited[newX][newY] = true;
                            q.push({newX, newY});
 

                        }

                    }

                }


            COUNT += 1;
            }
         

        }
    }

    cout << COUNT << endl;
}

int main(){
    string inPut[] = {"bbba", 
                     "baaa"};
    memset(visited, false, sizeof visited);
    connectedComponentString(inPut);
    
    return 0;
}
