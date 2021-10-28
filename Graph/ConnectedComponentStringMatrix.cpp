const n = 4;
const m = 4;

int visited[n][m];

const int dx[] = {0, 1, -1, 0}; 
const int dy[] = {1, 0, 0,  1}; 

bool is_visited(int x, int y, string inPut[], char c){

    if (x>=0 and y>=0 and x < n and y < n){
        if (visited[x][y] == false and inPut[x][y] ==c)
            return true;
        else return false;



    }
    else return false;


}
int COUNT;
void connectedComponentString(string inPut[]){

    for (i = 0; i < n; ++i){
        for (j = 0; j < m; ++j){
            if (visited[i][j] == false){
                char c = inPut[i][j]; // save the char that is not visited
                visited[i][j] = true;
            
                queue<pair<char, char> > q;
                q.push({i,j});
                
                while (!q.empty()){
                    pair<char, char> temp_q = q.front();
                    q.pop();
                    int x = temp_q.first, y = temp.second;

                    for (int i = 0; i<4; ++i){
                        int newX = x +dx[i];
                        int newY = y +dy[i];
                        if (is_visited(newX, newy, inPut, c)){
                            
                            visited[newX][newX] = true;
                            q.push({newX, newY});
 

                        }

                    }




                }


            COUNT += 1;
            }
            


        }
    }


}



int main(){
    string inPut[] = {"bbba", 
                    "baab",
                    "aaab",
                    "cbbc" };
    connectedComponentString(inPut);
}