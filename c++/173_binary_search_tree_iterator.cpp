/*

173. Binary Search Tree Iterator

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushNodes(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!nodeStack.empty());
    }
    /*  Test with:
                8
               /
              4
            /  \
           2    6
          / \   /\
         1   3 5  7
    */
    /** @return the next smallest number */
    int next() {
        TreeNode *smallest = nodeStack.top();
        nodeStack.pop();
        pushNodes(smallest->right);
        return smallest->val;
    }
private:
    // Save nodes in a stack
    stack<TreeNode *> nodeStack;
    // Push all the left nodes in the stack (i.e., smallest at top)
    void pushNodes(TreeNode *node) {
        while(node) {
            nodeStack.push(node);
            node = node->left;
        }
    }
};

/*
 *
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
