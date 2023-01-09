/*144. Binary Tree Preorder Traversal

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]

Given the root of a binary tree, return the preorder traversal of its nodes' values.

preorder traversal and inorder traversal : 

    preorder : traverse to left untill root  = nullptr then root->right, but we get the root->val in each step
    inorder  : traverse to left until root == nullptr, then get the root->val from the last left node

    


*/


#include<iostream>
#include<vector>


class Solution{
private:
    struct TreeNode{

        int val;
        TreeNode* left;
        TreeNode* right;

        /*constructor*/
        TreeNode(): val(0), left(nullptr), right(nullptr), {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr), {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}    

    };

    std::vector<int>ans;
    
public:
    std::vector<int>  preorderTraversal(TreeNode* root){
        /*ask the question : preorder, if current root is not null, then get its value and keep moving to the left side until root == nullptr then move to the right*/
        if(root){
            ans.emplace_back(root->val);
            /*keep moving to the left side */
            preorderTraversal(root->left);

            preorderTraversal(root->right);
        }
        
        return ans;
    }
};



