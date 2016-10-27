/*

144. Binary Tree Preorder Traversal

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)   return result;
        stack<TreeNode*> s;
        s.push(root);
        while ( !s.empty() )
        {
            TreeNode* current = s.top();
            result.push_back(current->val);
            s.pop();
            // Do the right side first since it's stack
            if(current->right)
                s.push(current->right);
            if(current->left)
                s.push(current->left);
        }
        return result;
    }
};

/*
// recursive with helper
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> v;
    preTraversal(root, v);
    return v;
}
void preTraversal(TreeNode* root, vector<int>& v){
    if(!root) return;
    v.push_back(root->val);
    preTraversal(root->left, v);
    preTraversal(root->right, v);
}
*/
