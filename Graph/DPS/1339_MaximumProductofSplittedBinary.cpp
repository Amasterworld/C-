/*1339. Maximum Product of Splitted Binary Tree
Given the root of a binary tree, split the binary tree into two subtrees by removing 
one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large,
 return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. 
Their product is 110 (11*10)

Example 2:

Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.
Their product is 90 (15*6)
*/

/*SOLUTION: - using dfs to calculate the sum of all values in a tree
            - using dfs again to calculate the products after disconnecting each edge
            - tracking the max_product, 
*/
#include<iostream>
#include<algorithm>

struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        /*constructor */
        TreeNode() : val(0), left(nullptr), right(nullptr){}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

class Solution{
    
    long long sum_all_elem = 0; // use long long to avoid overflow number
    long long ans = 0;
    const int MOD = 1e9+7;

    void sumEleTree(TreeNode* root){
        if(!root){
            return;
        }
        sum_all_elem += root->val;
        sumEleTree(root->left);
        sumEleTree(root->right);
    }

    int dfs(TreeNode* root){
        
        if(!root){
            return 0;
        }
        long long sum_left = dfs(root->left);
        long long sum_right = dfs(root->right);
        long long sum_subtree = sum_left + sum_right + root->val;
        ans = std::max(ans, sum_subtree * (sum_all_elem - sum_subtree));
        return sum_subtree;
    }
public: 
    int maxProduct(TreeNode* root) {
        
        sumEleTree(root); // get the sum of all elements in  the given tree
        dfs(root);
        return ans % MOD;
    }
};

        
