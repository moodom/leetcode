// Source : https://leetcode.com/problems/symmetric-tree/
// Author : FangY
// Date   : 2019-1-12
/*******************************************************************************
*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
*
*For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
*
*    1
*   / \
*  2   2
* / \ / \
*3  4 4  3
*But the following [1,2,2,null,3,null,3] is not:
*    1
*   / \
*  2   2
*   \   \
*   3    3
*Note:
*Bonus points if you could solve it both recursively and iteratively.
*******************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nums;
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return compareTreeNode(root->left,root->right);
    }
    bool compareTreeNode(TreeNode* left_node,TreeNode* right_node){
        if(!left_node && !right_node) return true;
        if(!left_node || !right_node) return false;
        if(left_node->val!= right_node->val) return false;
        return compareTreeNode(left_node->left,right_node->right)&&compareTreeNode(left_node->right,right_node->left);
    }

};


