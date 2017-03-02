/*

530. Minimum Absolute Difference in BST

Given a binary search tree with non-negative values, 
find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.

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
    // Time: O(n)
    // Space: O(h) h is height of tree
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX, pre = -1;
        inorder(root, res, pre);
        return res;
    }
private:
    void inorder(TreeNode* root, int & res, int & pre) {
        if(root->left) inorder(root->left, res, pre);
        if (pre >= 0) res = min(res, root->val - pre);
        pre = root->val;
        if(root->right) inorder(root->right, res, pre);
    }
};
