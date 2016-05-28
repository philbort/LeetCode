/*

98. Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

*/

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
    bool isValidBST(TreeNode* root) {
        if (!root)  return true;
        return ( isLessThan(root->left,root->val) &&
                 isGreaterThan(root->right, root->val) &&
                 isValidBST(root->left) &&
                 isValidBST(root->right) );
    }
private:
    bool isLessThan(TreeNode* root, int val) {
        if (!root)  return true;
        while(root) {
            if(root->val >= val)
                return false;
            root = root->right;
        }
        return true;
    }
    bool isGreaterThan(TreeNode* root, int val){
        if (!root)  return true;
        while(root) {
            if(root->val <= val)
                return false;
            root = root->left;
        }
        return true;
    }
};
