/*Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
    
  Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
  
      Output: true
          
 Example 2:         
 Input: root1 = [1,2,3], root2 = [1,3,2];root1 -> 1
                                                /   \
                                               2     3
Output: false
*/

/*Solution:  traverse in each root (dfs) and using a vector to store the values t the end, compare two vector, 


*/
class Solution{
        
    dfs(TreeNode* root, vector<int>& leaf_val){
        /*base condition*/
        if(!root)
            return;
        /*if this node is a leaf*/
        if(!root->left && !root->right){
            leaf_val.emplace_back(root->val);
        }
        dfs(root->left, leaf_val);
        dfs(root->right, leaf_val);
    }

 public:
     bool leafSimilar(TreeNode* root1, TreeNode* root2) {
     
        vector<int>leaf_val1; // store leaf values of tree1
        vector<int>leaf_val2; // store leaf values of tree2
        
         dfs(root1, leaf_val1);
         dfs(root2, leaf_val2);
         return leaf1_val1 == leaf_val2;      
         
     }   
    
};
    
