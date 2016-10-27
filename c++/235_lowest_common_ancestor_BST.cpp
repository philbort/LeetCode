/*

235. Lowest Common Ancestor of a Binary Search Tree 

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6.
Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root || !p || !q)
            return NULL;

        if(p->val>q->val)
        {
            std::swap(p,q);
        }
        
        if(root->val >= p->val && root->val <= q->val)
            return root;
        else if(root->val < p->val)
            return lowestCommonAncestor(root->right,p,q);
        else
            return lowestCommonAncestor(root->left,p,q);
    }
};