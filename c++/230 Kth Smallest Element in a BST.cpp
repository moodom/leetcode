// Source : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Author : FangY
// Date   : 2019-1-12
/*******************************************************************************
*Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
*
*Note:
*You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
*
*Example 1:
*
*Input: root = [3,1,4,null,2], k = 1
*   3
*  / \
* 1   4
*  \
*   2
*Output: 1
*Example 2:
*
*Input: root = [5,3,6,2,4,null,null,1], k = 3
*       5
*      / \
*     3   6
*    / \
*   2   4
*  /
* 1
*Output: 3
*Follow up:
*What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
    int i=0;
    int k_num;
    int kthSmallest(TreeNode* root, int k) {
        inordeTreeWalk(root,k);
        return k_num;
    }
    void inordeTreeWalk(TreeNode* node,int k){
        if(node->left) inordeTreeWalk(node->left,k);
        i++;
        if(i==k){
            k_num=node->val;
            return;
        }
        if(node->right) inordeTreeWalk(node->right,k);
    }
};

