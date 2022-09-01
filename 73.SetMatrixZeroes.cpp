/*73. Set Matrix Zeroes - leetcode
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place

Example 1:



Input: matrix = [[1,1,1],
                 [1,0,1],
                 [1,1,1]]
Output: [[1,0,1],
         [0,0,0],
         [1,0,1]]

Example 2:

Input: matrix = [[0,1,2,0],
                 [3,4,5,2],
                 [1,3,1,5]]
Output: [[0,0,0,0],
         [0,4,5,0],
         [0,3,1,0]]
*/
/*SOLUTION:
/*SOLUTION: create a ans matrix with the same matrix's dimention but all elements are 0
first we traverser the matrix following by rows, if matrix[i][j] != 0, hence copy the column j to the ans
else break 
then traverser matrix by columns, if matrix[j][i] == 0, break and change all element in this column j to 0



SC: O (m*n)
*/

#include<iostream>
#include<vector>

class Solution{

public:

    void setZeroes(std::vector<std::vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();
        /*create a vector ans with all initial elements  = 0 */
        std::vector<std::vector<int>> ans(rows, std::vector<int>(cols, 0));
        
        /*traverser  rows of the matrix*/
        for (int i = 0; i < rows; ++i){
            bool flag = false;
            for(int j = 0; j <cols; ++j){
                /*if one of elements in row == 0 hence change flag and break*/
                if(matrix[i][j] == 0){
                    flag = true;
                    break;
                }
                               
            }
            /*if none element in row == 0 hence copy it to ans*/
            if (!flag){
                for (int j = 0; j < cols; ++j){
                    ans[i][j] = matrix[i][j];
                }
            }
        }

        /*traverser  cols of the matrix*/
        for (int i = 0; i < cols; ++i){
            bool flag = false;
            for(int j = 0; j < rows; ++j){
                /*if one of elements in row == 0 hence change flag and break*/
                if(matrix[j][i] == 0){
                    flag = true;
                    break;
                }
                               
            }
            /*if one element in row == 0 hence replace all elements in this row = 0*/
            if (flag){
                for (int j = 0; j < rows; ++j){
                    ans[j][i] = 0;
                }
            }
        }
        /*finally assign matrix = ans*/
        matrix = ans;
    }


};

int main(){

    std::vector<std::vector<int>> matrix{{1,1,1},
                                         {1,0,1},
                                         {1,1,1}};
    Solution s;
    s.setZeroes(matrix);

    for(int i = 0; i < matrix.size(); ++i){
        for(int j=0; j<matrix[0].size();++j){
            std::cout<<matrix[i][j];
        }
        std::cout<<'\n';
    }

}
