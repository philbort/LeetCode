/*

129. Sum Root to Leaf Numbers

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

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
    int sumNumbers(TreeNode* root) {
        if(!root)   return 0;
        return Helper(root, 0);
    }
    
private:
    int Helper(TreeNode* root, int x) {
        // Previous value up to this node
        int pre = 10 * x + root->val;
        // If no more nodes, cur = pre
        if(!root->left && !root->right)
            return pre;
        // Current value at this node
        int cur = 0;
        // Include left 
        if(root->left)
            cur += Helper(root->left, pre);
        // Include right
        if(root->right)
            cur += Helper(root->right, pre);
        return cur;
    }
};
