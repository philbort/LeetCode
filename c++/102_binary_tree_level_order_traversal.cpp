/*

102. Binary Tree Level Order Traversal

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
	
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        return result;
    }
    
    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)   return result;
        queue<TreeNode*> q;
        // Use one additional queue to track the nodes at the same level
        queue<TreeNode*> curLevel;
        q.push(root);
        while(!q.empty()) {
            vector<int> curResult;
            while(!q.empty()) {
                curResult.push_back(q.front()->val);
                curLevel.push(q.front());
                q.pop();
            }
            result.push_back(curResult);

            while (!curLevel.empty()) {
            if(curLevel.front()->left)   q.push(curLevel.front()->left);
            if(curLevel.front()->right)  q.push(curLevel.front()->right);
            curLevel.pop();
            }
        }
        return result;
    }
    
};


/* Pretty smart recursion solution

vector<vector<int>> ret;

void buildVector(TreeNode *root, int depth)
{
    if(root == NULL) return;
    if(ret.size() == depth)
        ret.push_back(vector<int>());

    ret[depth].push_back(root->val);
    buildVector(root->left, depth + 1);
    buildVector(root->right, depth + 1);
}

vector<vector<int> > levelOrder(TreeNode *root) {
    buildVector(root, 0);
    return ret;
}

*/
