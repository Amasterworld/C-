/*
  main.cpp
  240.Search2DMatrixII - leetcode

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

      - Integers in each row are sorted in ascending from left to right.
      - Integers in each column are sorted in ascending from top to bottom.

 Input: matrix = [[1, 4, 7, 11, 15],
                  [2, 5, 8, 12, 19],
                  [3, 6, 9, 16, 22],
                  [10,13,14,17, 24],
                  [18,21,23,26 ,30]],
 target = 5
 Output: true
 
 
  
Solution: Binary search, Time complexity O(nlogn)
                         Space complexity O(1)
 
 Created by Thao Nguyen on 31.07.22.
*/
#include <iostream>
#include <vector>
class Solution{
    unsigned long n{}, m{};
public:
    //constructor
    //Solution(){}
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target){
        
        n = matrix.size();
        m = matrix[0].size();
        unsigned long l{}, r{}, mid{};
        
        for (auto sub_vec : matrix){
            // target cannot be in sub_vec then continue
            if (target > sub_vec[n-1] || target < sub_vec[0]){
                continue;
            }
            l = 0; r = n - 1;
            while (l < r){
                
                mid = l + (r - l)/2;
                if (sub_vec[mid] == target){
                    return true;
                }
                else if (mid  > target){
                    l = mid +1;
                }
                else{
                    r = mid;
                }
            }
        }
        
        return false;
    }
};
int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> matrix = {{1, 4, 7, 11, 15},
                               {2, 5, 8, 12, 19},
                               {3, 6, 9, 16, 22},
                               {10,13,14,17, 24},
                               {18,21,23,26 ,30}};
    int target = 5;
    Solution s;
    std::cout<<s.searchMatrix(matrix, target)<<'\n'; // output 1.
    
    
    return 0;
    //passed all test cases in leetcode engine
    
}
