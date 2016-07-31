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
        vector<TreeNode*> dp(1, NULL);
        /* The idea is: the new number is bigger than
           all the old numbers. So there are two options:
           1. if the new number is the root, add all
           the past trees to its left
           2. it the new number is not the root, add new
           number to every right sub-tree placeof the past
           trees and link all the right child to its left
        
        */
        for (int i = 1; i <= n; i++) {
            vector<TreeNode*> current;
            for (int j = 0; j < dp.size(); j++){
                // the new number is the root
                TreeNode* newroot = new TreeNode(i);
                TreeNode* oldroot = clone(dp[j]);
                newroot->left = oldroot;
                current.push_back(newroot);
                // the new number is not the root
                TreeNode* p = oldroot;
                while(p) {
                    
                    TreeNode* r = p->right;
                    TreeNode* newnode = new TreeNode(i);
                    p->right = newnode;
                    newnode->left = r;
                    current.push_back(clone(oldroot));
                    p->right = r;
                    p = p->right;
                }
            }
            dp = current;
        }
        return dp;
    }
private:
    TreeNode* clone(TreeNode* root) {
        if(!root)  return NULL;
        TreeNode* newroot = new TreeNode(root->val);
        newroot->left = clone(root->left);
        newroot->right = clone(root->right);
        return newroot;
    }
};

/*

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
    
*/
