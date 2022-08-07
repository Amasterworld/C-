/*62.UniquePath- leetcode
 * There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
 * The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
 * The robot can only move either down or right at any point in time.
 * Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
 * The test cases are generated so that the answer will be less than or equal to
 * Input: m = 3, n = 2 O
 * Output: 3
 * Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

SOLUTION: we can easily see that the current position of a robot (do not count 0,0) is moved from its left or its above (except when robot stay at the  edges)
 and thw two position also is moved from the possible their left and above position. for example robot at P(5,5), that means it can come from P1(5,4) or P(4,5)-> and it is the same for P1 and P2
 that mean if we can sum all of them we get the value for (5,5)
 -> DP +mem is the best solution. Time complexity is O(m*n)
 */
#include <iostream>
#include <vector>
#include <memory>

class Solution {
public:
    int uniquePaths(int m, int n) {
        // create a vector with dp mxn and all values in cells  = 1
        std::vector<std::vector<int> > dp(m, std::vector<int>(n, 1));

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // then the final result is stored at the last cell of the dp
        return dp[m - 1][n - 1];
    }
};

/*Another approach is using recursion +memorization
 * class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &dp, int& m, int& n) {
        if(i == m-1 || j == n-1) return 1;
        if(dp[i][j] != 0)return dp[i][j];

        dp[i][j] = solve(i+1, j, dp, m, n) + solve(i, j+1, dp, m, n);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , 0));
        return solve(0, 0, dp, m, n);
    }
};
 *
 * */

int main() {
    //Solution s; // if want to use object cout<<s.uniquePaths(m, n);
    int m = 3, n = 7;
    // using smart pointer here only for fun
    std::unique_ptr<Solution> ptr = std::make_unique<Solution>();

    std::cout << ptr->uniquePaths(m, n) << '\n'; // Output 28

    //int m = 3, n = 2;
    // std::cout<<ptr->uniquePaths(m, n)<<'\n'; // Output 3
    return 0;
}
