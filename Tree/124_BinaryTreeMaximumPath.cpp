/*24. Binary Tree Maximum Path Sum - level HARD

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes 
in the sequence has an edge connecting them. A node can only appear in the sequence at most once. 
Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path. 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

Example 3: replace val = -10 of thwe root  in example 2 by 1

Input: root = [1,9,20,null,null,15,7]
Output: 45
Explanation: The optimal path is 1->9>15 -> 20 with a path sum of 15 + 20 + 1 + 9 = 45.

*/

/*SOLUTION: uses DFS algorithm to calculate the maximum sum of left and right side at each node
Note that because of the val in nodes can be negative, so if the sum of left or right side is negative, 
we can reject to add it in the sum (in other word add 0)

*/
#include<iostream>
#include<algorithm>
struct TreeNode{
    
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){} 
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){} 
};

class solution{

    int dfs(TreeNode* root, int& max_sum_path){

        if (!root){
            return 0;
        }
        int left_side =  std::max(0, dfs(root->left, max_sum_path)); // the sum at the left side is negative hence we add it with 0
        int right_side = std::max(0, dfs(root->right, max_sum_path)); // the sum at the right side is negative hence we add it with 0
        max_sum_path = std::max(max_sum_path, left_side + right_side + root->val);
        /*get the higher betwenn the left side and right side of the current node */
        return std::max(left_side, right_side) + root->val;
    }
public:
    int maxPathSum(TreeNode* root){

        int max_sum_path = INT_MIN; // not 0 because the val in node can be negative
        dfs(root, max_sum_path);
        return max_sum_path;
    }

};