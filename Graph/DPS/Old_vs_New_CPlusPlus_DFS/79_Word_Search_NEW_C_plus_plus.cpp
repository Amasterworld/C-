#include<iostream>
#include<functional> // to use function<> in c++
#include<vector>

class Solution{
    
    int dir[5] = {0, -1, 0, 1, 0};
                  
public:

    bool exist(std::vector<std::vector<char>>& board,std::string word) {

        int rows = board.size();
        int cols = board[0].size();
        int word_size = word.size();
        int len_step = 0; 
        
        /*because we use std::function<> to store lamda function not like old techinique where we must 
        create the function outside the  exist function hence we must pass the ref board and word
        */
        std::function<bool(int ,int, int) > search_dfs;
        /*search_dfs now can be placed inside the exist function, then it can be placed as closer as possible to where it is being usedg
        and because search_dfs is placed insde exist function, so no need to pass by ref vector board and string word. 
        */
        search_dfs = [&](int x, int y, int len_step) -> bool {
            
            if (len_step == word_size){
                return true;
            }

            if(x < 0 || x == rows || y < 0 || y == cols){
                return false;
            }

            if (board[x][y] != word[len_step]){
                return false;
            }
            /*check 4 dirs from the cell board[x][y]*/
            for(int d = 0; d < 5; ++d ){
                if(search_dfs(x + dir[d], y + dir[d+1], len_step+1 )){
                    return true;
                }
            }
            return false;
        };
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                /*check whether board[i][j] == the firs letter in word (word[0]), if yes keep checking in the 4 dir*/
                if (board[i][j] == word[0]){
                    
                    if (search_dfs(i, j, len_step)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main(){
    std::vector<std::vector<char>>board = {{'A','B','C','E'},
                                           {'S','F','C','S'},
                                           {'A','D','E','E'}};
    std::string word = "ABCCED";
    Solution s;
    //std::cout<<s.exist(board, word)<<'\n'; // output :  1 == true
    
    std::cout<<s.exist(board, word)<<'\n';     
}
        