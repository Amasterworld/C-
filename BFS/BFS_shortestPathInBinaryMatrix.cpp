#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;




class BFS{
    
    public:

      
        vector<pair<int,int>>trajec;
        
        void printArray(vector<vector<int> >&grid, HANDLE &handle, WORD defaultConfig, WORD searchConfig){
            
            //vector<vector<int>>result;
           // non_common(trajec, useless_point,result);

            
           /*for (int i=0; i< trajec.size();++i){
                for(int j=0;j<trajec[0].size();++j){

                    //cout<<" last troject ";
                    cout<< trajec[i][j]<<" ";
                }
                cout<<endl;
            }
             cout<<endl;  */
            

            bool flag =false;
            for (int i=0; i< grid.size();++i){
                for(int j=0;j<grid[0].size();++j){
                    for(int k=0;k<trajec.size();++k){
                        if(i == trajec[k].first and j == trajec[k].second ){
                            
                            if(grid[i][j] >=10){
                            SetConsoleTextAttribute(handle,searchConfig);
                            cout<< grid[i][j]<<"    ";

                            }
                            else if (grid[i][j]<10){
                            
                            SetConsoleTextAttribute(handle,searchConfig);
                            cout<< grid[i][j]<<"     ";

                            }
                           flag = true;
                           break;
                        }
                        

                        else{
                            flag =false;
                        }
                        
                        
                        
                    }
                    if (flag){
                       // cout<<"i = "<<i <<" j=  "<<j<<endl;
                        continue;
                    }
                    if(grid[i][j] >=10){
                        SetConsoleTextAttribute(handle,defaultConfig);
                        cout<< grid[i][j]<<"    "; 
                    }
                    else {
                        SetConsoleTextAttribute(handle,defaultConfig);
                        cout<< grid[i][j]<<"     "; 
                        
                    }
                    
              //  cout<<endl;
                    
                }
                
                cout<<endl;
                
                
            
            }
           // SetConsoleTextAttribute(handle,defaultConfig);
    
            
            

        }

      

        

        bool is_valid(int x, int y,  vector<vector<int> >grid){
            int m = grid.size(), n = grid[0].size();
            return (x>=0 && x<m && y>=0 && y<n);
        }

       

        void BFS_shortestPath(vector<vector<int>>& grid, int x_sta, int y_sta, int x_end, int y_end){
            
            bool reached = false;
            int m = grid.size(), n= grid[0].size();
            HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

            //default configuration
            CONSOLE_SCREEN_BUFFER_INFO Info;
            WORD defaultAttributes = 0;
            GetConsoleScreenBufferInfo(screen, &Info);
            defaultAttributes = Info.wAttributes;;

            // searching attributes

            WORD searchAttributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;

            
            int dx[] = {1,0,0,-1,1,-1,1,-1};
            int dy[] = {0,1,-1,0,1,-1,-1,1};

            if (grid[x_sta][y_sta] != 1 ||  grid[x_end][y_end] != 1) {
              
              cout<<"check input ";
              return;
              //return -1;
          }
            int visited[m][n];
            memset(visited, 0, sizeof(visited));
            int visited2[m][n];
            memset(visited2, 0, sizeof(visited2));
            
            
            grid[x_sta][y_sta] = 1;
            visited[x_sta][y_sta] = 1;
            //trajec.push_back({x_sta, y_sta});
            queue<pair<int,int>> q;
            q.push({x_sta, y_sta});
            
            while (!q.empty()){
               
                pair<int,int> temp_q = q.front();
                q.pop();
                int new_x, new_y;
                // dead point is a point can be a point of traject but it is not shortess path.
                for (int i= 0; i<8;++i){
                     
                    new_x = temp_q.first  + dx[i];
                    new_y = temp_q.second + dy[i];

                    if (is_valid(new_x, new_y, grid) and !(visited[new_x][new_y])  and grid[new_x][new_y] == 1){

                        visited[new_x][new_y] = temp_q.first;
                        visited2[new_x][new_y] = temp_q.second;
                        q.push({new_x, new_y});
                        // increase 1 each adjuest cells if they are found
                        grid[new_x][new_y] = grid[temp_q.first][temp_q.second] + 1;
                       // trajec.push_back({new_x, new_y});
                        //trajec.emplace_back(initializer_list<int>{temp_q.first, temp_q.second});
                        //printArray(grid, new_x, new_y,  screen, defaultAttributes, searchAttributes);
                        
                    }
                   
                     if (new_x == x_end and new_y == y_end){
                        reached = true;
                       
                        // return;
                      // return grid[x_end][y_end] -1 ; // -1 because we start0ed at 2 
                                               
                    }


                }
                
                
                   

                        
                        
                   
                
                
            }

            trajec.push_back({x_end, y_end});
            while (x_end != x_sta || y_end != y_sta){

                int x_end_upda = x_end, y_end_upda = y_end;
                trajec.push_back({visited[x_end][y_end], visited2[x_end][y_end]});
                x_end  = visited[x_end_upda][y_end_upda]; y_end = visited2[x_end_upda][y_end_upda];
            }

            reverse(trajec.begin(),trajec.end());
          /*  cout<<"Number cells visited in the shortest path is: "<<trajec.size()-2<<endl;
            for(int i=0;i<trajec.size();i++){
                 cout<<trajec[i].first<<" "<<trajec[i].second<<endl;
            }*/
            if (reached){
                 printArray(grid,  screen, defaultAttributes, searchAttributes);

            }
            else{
                cout<<" cannot reach the end point "<<endl;
            }
         //   return -1;
            
        }

};
//void sortArrayAscending(int *array, int size);
//void printArray(int *array, bool *swaps, int , HANDLE &, WORD , WORD );
//void printUnsortedArray(int *array, int size);

int main()
{
    string hyphen;
    const string progTitle = "Breath first search to find the shortest path in binary matrix";
    const int numHyphens = 100;

    hyphen.assign(numHyphens, '-');

    const int size = 8;

    //int values[size] = { 21, 16, 23, 18, 17, 22, 20, 19 };

    cout << hyphen  << endl;
    cout << "     " << progTitle << endl;
    cout << hyphen  << endl;

    cout << "\n  This program will return the distance from the given start point to end point "<< endl;

    int x_sta, y_sta, x_end, y_end;
    vector<vector<int> > grid =  {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                  {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                                  {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                                  {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                                  {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                                  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                  {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};

    cout<< "Please enter x start ";
    cin>>x_sta;
    cout<<endl;

    cout<< "Please enter y start ";
    cin>>y_sta;
    cout<<endl;

    cout<< "Please enter x end ";
    cin>>x_end;
    cout<<endl;

    cout<< "Please enter y end ";
    cin>>y_end;
    cout<<endl;

    BFS bfs_ssp;
    
    if (!bfs_ssp.is_valid(x_sta,y_sta,grid) ){
        cout<< "Please input valid values for  x and y START "<<endl;
        // also should check x end and y end.
    }
    else if (!bfs_ssp.is_valid(x_end,y_end,grid)) {
         cout<< "Please input valid values for  x end and y end"<<endl;

    }
    bfs_ssp.BFS_shortestPath(grid,  x_sta, y_sta, x_end, y_end);

    /*int dist = bfs_ssp.BFS_shortestPath(grid,  x_sta, y_sta, x_end, y_end);
    if ( dist  != -1){
        cout<<"dist = "<<dist<<endl;
        for (int i=0; i< grid.size();++i){
            for (int j=0; j<grid[0].size();++j){
                cout<<grid[i][j]<<" ";
                if (j == grid[0].size() - 1){
                    cout<<endl;
                }
            }
        }
    }*/
    cin.ignore(cin.rdbuf()->in_avail());
    cout << "\n\n\n\nPress only the 'Enter' key to exit program: ";
    cin.get();
}