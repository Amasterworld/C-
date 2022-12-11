/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 /*SOLUTION: uses DFS algorithm to to get the sum of left and right branch  of each node,
 */
class Solution {

    
public:
    int maxPathSum(TreeNode* root) {
        int max_path_sum = INT_MIN;
        std::function<int(TreeNode*, int)> dfs;

        dfs =[&](TreeNode* root, int max_pat_sum) ->int {
            
            if(!root)
                return 0;
            int left_side = max(0, dfs(root->left, max_pat_sum));
            int right_side = max(0, dfs(root->right, max_pat_sum));
            max_path_sum = max(max_path_sum, left_side + right_side + root->val);

            return max(left_side, right_side) + root->val;
        };
        dfs(root, max_path_sum);
        return max_path_sum;
        
    }
};
