/*

113. Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

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

    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        vector<vector<int>> result;
        vector<int> current;

        Helper(root, result, sum, current);
        
        return result;
    }

private:

    void Helper(TreeNode* root, vector<vector<int>> & result, int sum, vector<int> current) {

        if (!root)  return;

        current.push_back(root->val);

        if (sum == root->val && !root->left && !root->right ) {
            result.push_back(current);
            return;
        }

        Helper(root->left, result, sum - root->val, current);
        Helper(root->right, result, sum - root->val, current);
    }
};

