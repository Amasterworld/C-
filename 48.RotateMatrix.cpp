/*You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise)
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
 */


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    void rotate(vector<vector<int>>&matrix){
        // to rotate a matrix + 90 degree  we should use TRANSPOSE and REFLECT a matrix
        // - transpose a matrix is a process we swap the elements in matrix, following its diagonal
        // that means swap a[j][i] for a[j][i]
        // - reflect the matrix is a process we swap the value elements ain matrix, following its vertical axis, a[i][j] swap for a[i][col-1-j]
        transpose(matrix);
        reflect(matrix);

    }
    void transpose(vector<vector<int>>& matrix){
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; ++i){
            for (int j = i+1; j < col; ++j){
                swap(matrix[i][j], matrix[j][i]);

            }
        }
    }
    void reflect(vector<vector<int>>& matrix){
        int row = matrix.size();
        int col = matrix[0].size();

        for ( int i = 0; i < row; ++i){
            for(int j = 0; j < col/2; ++j){ // we swap elements by vertical axis then we only have to move a half of col
                swap(matrix[i][j], matrix[i][col-1-j]); // 0,0 for 0, col-1-0

            }
        }

        
    }

};

int main(){

    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    Solution solu;
    for (int i = 0; i< matrix.size(); ++i){
        for (int j = 0; j< matrix[0].size(); ++j){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}