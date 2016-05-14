/*

257. Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

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

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root)  return ans;
        Helper(root, ans, to_string(root->val));
        return ans;
    }

private:

    void Helper(TreeNode* root, vector<string>& ans, string current) {
        if(!root->left && !root->right){
            ans.push_back(current);
            return;
        }
        if(root->left)  Helper(root->left, ans, current +"->" + to_string(root->left->val));
        if(root->right)  Helper(root->right, ans, current +"->" + to_string(root->right->val));
    }
};
