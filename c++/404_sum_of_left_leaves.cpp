/*

404. Sum of Left Leaves

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

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
    // DFS Solution:
    // Time: O(n)
    // Space: O(n)
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)   return 0;
        if(root->left && !root->left->left && !root->left->right)
            return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};


/*  BFS Solution:
    Time: O(n)
    Space: O(n)

    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)   return 0;
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left)   q.push(cur->left);
            if(cur->right)  q.push(cur->right);
            if(cur->left && !cur->left->left && !cur->left->right)
                sum += cur->left->val;
        }
        return sum;
    }
    
*/
