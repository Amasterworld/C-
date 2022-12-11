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
