/*79. Word Search - leetcode

Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally 
or vertically neighboring. The same letter cell may not be used more than once.
Example 1:

                  -   -   -
Input: board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]], 
                  -   -   -
                word = "ABCCED"
Output: true

Example 2:

Input: board = [["A","B","C","E"], ["S","F","C","S"],  ["A","D","E","E"]], word = "SEE"
                          -   -
Output: true

Example 3: [
    "C","A","A"],
    ["A","A","A"],
    ["B","C","D"]] word = "AAB"  Output: true
*/

/* SOLUTION: with this kind of problem, we always can solve with DFS algorithm
so Time complexity for DFS is O(m*n) , m and n are rows and cols of the board
and at each cell we have to check 4 dirs, so total TC is = O(m*n*4^word.size())
*/
#include<iostream>
#include<vector>
class Solution{
private:
    /*path*/
    std::vector<std::pair<int, int>> path;
    /*4 dirs*/
    int dx[4] =  {0, 1, -1,  0};
    int dy[4] =  {1, 0,  0, -1};

    bool search_dfs(std::vector<std::vector<char>>& board, std::string& word, int x, int y, int len_step){

        int rows = board.size();
        int cols = board[0].size();
        int word_size = word.size();

        /*consition to stop dfs, if at the end len_step == word.size() -> all letters in word are matched  */
        if ( len_step == word.size()){
            return true;
        }

        /*board at x and y should be valid*/
        if(x < 0 || x == rows || y < 0 || y == cols ){
            return false;
        }
        /*stop searching this dir if current char in board, board[x][y],  != corresponding letter in word, word[len_step]*/
        if(board[x][y] != word[len_step]){
            return false;
        }
        

        /*search in 4 dirs*/
        for(int d = 0; d < 4; ++d){
            /*save the current letter*/
            char save_curr_letter = word[len_step];
            /*mark it is visited*/
            board[x][y] = '.';
            path.emplace_back(x,y);
            if (search_dfs(board, word, x + dx[d], y + dy[d], len_step+1)){
                return true;
            }
            /*return the save char
            we must return the save_char because with the dfs algorithm, each cell in the board can be seens as the "root of tree"
            whenever we switch to a new root(a new cell) then we must re-set that other cells are not visited -> see example 3 to understand more detal.
            */
            board[x][y] = save_curr_letter;
            /*reset path*/
            path.pop_back();
        }
        return false;
    }

public:
    bool exist(std::vector<std::vector<char>>& board,std::string word) {

        int rows = board.size();
        int cols = board[0].size();
        int word_size = word.size();
        int len_step = 0; // at the end if len_step == word_size that mean the char word is in board -> return true
        
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                /*check whether board[i][j] == the firs letter in word (word[0]), if yes keep checking in the 4 dir*/
                if (board[i][j] == word[0]){
                    
                    if (search_dfs(board, word, i, j, len_step)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    void print_path(){

        std::cout<<"word in board is following this path "<<'\n';
        for(const auto& coord: path){
            
            std::cout<<"("<<coord.first<<", "<<coord.second<<")";
        }
        std::cout<<'\n';
        path.clear();
    }
};

int main(){
    std::vector<std::vector<char>>board = {{'A','B','C','E'},
                                           {'S','F','C','S'},
                                           {'A','D','E','E'}};
    std::string word = "ABCCED";
    Solution s;
    //std::cout<<s.exist(board, word)<<'\n'; // output :  1 == true
    
    if (s.exist(board, word)){
       
        s.print_path();
    }
    std::vector<std::vector<char>>board_1 = {{'A','B','C','E'},
                                          {'S','F','C','S'},
                                          {'A','D','E','E'}};
    std::string word_1 = "SEE";
    
   if (s.exist(board_1, word_1)){
       
        s.print_path();
    }
}
