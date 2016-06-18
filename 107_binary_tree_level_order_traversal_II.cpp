/*

107. Binary Tree Level Order Traversal II 

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)   return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> curResult;
            // Use a size to track how many nodes we need to 
            // push to the current vector
            int size = q.size();
            for (int i = 0; i < size; i++) {
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                curResult.push_back(q.front()->val);
                q.pop();
            }
            result.push_back(curResult);
        }
        reverse(result.begin(), result.end());
        return result; 
    }
};

