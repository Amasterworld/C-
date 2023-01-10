/*101. Symmetric Tree

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
Input: root = [1,2,2,3,4,4,3]  
Output: true

Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false
*/

/*SOLUTION: the given tree is symmetric that mean the structure of left and right side and  vales of the corresponding nodes are the same
to compare the stucture and values of nodes of left and right side: -> create two pointers, one traverses to the left side, one to the right side
if the structure or vales of nodes are not the same return false


*/
#include<iostream>

class Solution{

private:
    struct TreeNode{

        int val{};
        TreeNode* left;
        TreeNode* right;

        /*constructors*/
        TreeNode() : val(0), left(nullptr), right(nullptr){}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}

    };

    bool dfsIsSym(TreeNode*  left, TreeNode*  right){

        /*base conditions*/
        /*if two pointers are nullptr, reach the leaves -> return true*/
        if(!left && !right){
            return true;
        }
        /*if one of pointers is nullptr but another is not -> not the same structure -> return false*/
        if(!left && right || left && !right){
            return false;
        }
        /*if the value of left node != right node -> return false*/
        if(left->val != right->val){
            return false;
        }
        /*keep traversing one pointer to the left side, one to the right side and check above condition  until return false or true*/
        bool l_r  = dfsIsSym(left->left, right->right); // left_right

         /*check whether right nodes of left side nodes == left nodes of right side*/
        bool rl_lr = dfsIsSym(left->right, right->left); // right_left_left_right
         /*at the end, if l_r and rl_lr are true then the given tree is symmetric */
        return l_r && rl_lr; 
        /* or         return dfsIsSym(left->left, right->right) && dfsIsSym(left->right, right->left); 
        */
    }


public:

    bool isSymmetric(TreeNode* root) {

        TreeNode* left  = root->left;
        TreeNode* right = root->right;

        return dfsIsSym(left, right);
    }
};
        
