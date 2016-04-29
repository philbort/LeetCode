/*

230. Kth Smallest Element in a BST

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
How would you optimize the kthSmallest routine?

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> a;
        inorderTraversal(root, a);
        return a[k-1];
    }
private:
    void inorderTraversal(TreeNode* root, vector<int> &a)
    {
        if(!root)
            return;
        inorderTraversal(root->left, a);
        a.push_back(root->val);
        inorderTraversal(root->right,a);
        return;
    }
};

/* traverse without saving the vector
void inorder(TreeNode* node, int& fid, int& k) {
    if (!node) return;
    inorder(node->left, fid, k);
    if (!k) return;
    fid = node->val;
    inorder(node->right, fid, --k);
}

int kthSmallest(TreeNode* root, int k) {
    int fid;
    inorder(root, fid, k);
    return fid;
}
*/

/* Use stack to traverse:

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        TreeNode *p = root;
        while(p || !st.empty())
        {
            while(p)
            {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            if(--k == 0)
                return p->val;
            st.pop();
            p = p->right;
        }
    }
};

*/

/* WTF answer:

int kthSmallest(TreeNode* root, int k) {
    return find(root, k);
}
int find(TreeNode* root, int& k) {
    if (root) {
        int x = find(root->left, k);
        return !k ? x : !--k ? root->val : find(root->right, k);
    }
}

*/