/*

94. Binary Tree Inorder Traversal   

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

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

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> nodes;
        stack<TreeNode*> toVisit;

        TreeNode* curNode = root;
        
        while (curNode || !toVisit.empty()) {
            if (curNode) {
                toVisit.push(curNode);
                curNode = curNode -> left;
            }
            else {
                curNode = toVisit.top();
                toVisit.pop();
                nodes.push_back(curNode -> val);
                curNode = curNode -> right;
            }
        }
        return nodes;
    }
};

/*
Recursive solution:

void inorder(TreeNode* root, vector<int>& nodes) {
    if (!root) return;
    inorder(root -> left, nodes);
    nodes.push_back(root -> val);
    inorder(root -> right, nodes);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> nodes;
    inorder(root, nodes);
    return nodes;
} 
Morris traversal:

vector<int> inorderTraversal(TreeNode* root) {
    TreeNode* curNode = root;
    vector<int> nodes;
    while (curNode) {
        if (curNode -> left) {
            TreeNode* predecessor = curNode -> left;
            while (predecessor -> right && predecessor -> right != curNode)
                predecessor = predecessor -> right;
            if (!(predecessor -> right)) {
                predecessor -> right = curNode;
                curNode = curNode -> left;
            }
            else {
                predecessor -> right = NULL;
                nodes.push_back(curNode -> val);
                curNode = curNode -> right;
            }
        }
        else {
            nodes.push_back(curNode -> val);
            curNode = curNode -> right;
        }
    }
    return nodes;
}

*/