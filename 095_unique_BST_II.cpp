/*

95. Unique Binary Search Trees II

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

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
    vector<TreeNode*> generateTrees(int n) {
        if(!n)  return vector<TreeNode*>();
        return helper(1, n);
    }
private:
    vector<TreeNode*> helper(int min, int max) {
        vector<TreeNode*> result;
        if(min > max){
            result.push_back(NULL);
            return result;
        }
        // i as the root value, loop from min to max
        for (int i = min; i <= max; i++) {
            // Values from min to i-1 goes to left sub-tree
            vector<TreeNode*> leftSubTree = helper(min, i-1);
            // Values from i+1 to max goes to right sub-tree
            vector<TreeNode*> rightSubTree = helper(i+1, max);
            // Go through every possible combination for left and right
            for (int j = 0; j < leftSubTree.size(); j++) {
                for(int k = 0; k < rightSubTree.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftSubTree[j];
                    root->right = rightSubTree[k];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};
