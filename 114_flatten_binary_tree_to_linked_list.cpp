/*

114. Flatten Binary Tree to Linked List 

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

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
    void flatten(TreeNode* root) {
        TreeNode* current = root;
        while(current) {
            if(current->left) {
                TreeNode* pre = current->left;
                while(pre->right)
                    pre = pre->right;
                pre->right = current->right;
                current->right = current->left;
                current->left = NULL;
            }
            current = current->right;
        }
    }
};

/* Recursion solution:

private:
    TreeNode *tail;
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        tail = root;
        if (root->left) {
            flatten(root->left);
            tail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        flatten(tail->right);
    }
    
*/

/* Naive solution, preorder first:

public:
    void flatten(TreeNode* root) {
        if(!root)   return;
        vector<int> nodes;
        preOrder(root, nodes);
        for (int i = 1; i < nodes.size(); i++) {
            root->left = NULL;
            if(!root->right)
                root->right = new TreeNode(0);
            root = root->right;
            root->val = nodes[i];
        }
    }
private:
    void preOrder(TreeNode* root, vector<int>& nodes) {
        if(!root)   return;
        nodes.push_back(root->val);
        preOrder(root->left, nodes);
        preOrder(root->right, nodes);
    }
    
*/
