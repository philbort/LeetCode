/*

103. Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    // Basically breadth first traversal with every other row reversed
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)   return result;
        queue<TreeNode *> q;
        q.push(root);
        bool RightToLeft = false;
        while(!q.empty()) {
            int size = q.size();
            vector<int> curLevel(size);
            for(int i = 0; i < size; i++) {
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                curLevel[i] = q.front()->val;
                q.pop();
            }
            if(RightToLeft)
                reverse(curLevel.begin(), curLevel.end());
            result.push_back(curLevel);
            RightToLeft = !RightToLeft;
        }
        return result;
    }
};
