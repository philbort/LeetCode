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

class Solution {

public:

    vector<int> preorderTraversal(TreeNode* root) {

        if(!root)
            return vector<int>();

        vector<int> ans;
        stack<TreeNode*> nodes;
        
        nodes.push(root);

        while ( !nodes.empty() )
        {
            TreeNode* current = nodes.top();
            ans.push_back(current->val);
            nodes.pop();
            if(current->right)
                nodes.push(current->right);
            if(current->left)
                nodes.push(current->left);
        }
        return ans;
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