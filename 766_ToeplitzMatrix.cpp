/*766. Toeplitz Matrix - leetcode
Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.


Example 1:

Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.

Example 2:

Input: matrix = [[1,2],[2,2]]
Output: false
Explanation:
The diagonal "[1, 2]" has different elements.

*/

/*SOLUTION:  very simple, firstly, traverse all diagonals from left  to right: diagonal 1: (0,0), (1,1), (2,2)
                                                                               2: (0,1), (1,2), (2,3) 
                                                                              ....                                                                            
if found any number != the value of initial cells  such as (0,0) or (0,1) return false

- secondly, traverse all diagonals from top to bottom such (1,0), (2,1)...
Note that: we do not need to check again from (0,0)
*/
#include<iostream>
#include<vector>
class Solution{
private:
    bool checkDiag(std::vector<std::vector<int>>& matrix, int x, int y){
        
        int r = matrix.size();      
        int c = matrix[0].size();
        int ini_val_diag = matrix[x][y];
        /*check all values*/
        while(r > x && c > y){
            if(matrix[x][y] != ini_val_diag){
                return false;
            }
            x++;
            y++; // note that we also can wrie while(r > x++ && c > y++) {// the same logic}  to make the code shorter
        }

        return true;
    }

public:
    bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {

        int r = matrix.size();      
        int c = matrix[0].size();

        /*check all values in the diagonals from left to right*/

        for(int i = 0; i < c; ++i){
            if(!checkDiag(matrix, 0, i)){
                return false;
            }
        }
        /*check all values in the diagonals from top to bottom, note that we do not check again j = 0 */
        for(int j = 1; j < r; ++j){
            if(!checkDiag(matrix, j, 0)){
                return false;
            }
        }
        return true;
    }

};

int main(){
    std::vector<std::vector<int>> matrix = {{1,2,3,4}, {5,1,2,3},{9,5,1,2}};
    Solution s;
    std::cout<< (s.isToeplitzMatrix(matrix) ? "true": "fasle"); // parenthesis here is important, because the precedence of ? operator is weeker than <<
    return 0;

}
