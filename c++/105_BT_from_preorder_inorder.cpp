/*

105. Construct Binary Tree from Preorder and Inorder Traversal 

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return Helper( preorder, 0, preorder.size()-1, 
                       inorder, 0, inorder.size()-1 );
    }
    
private:

    TreeNode* Helper(vector<int>& preorder, int left, int right,
                     vector<int>& inorder, int i, int j) 
    {
    if (left > right || i > j)
        return NULL;
    // The first element in the current preorder vector is the current node
    int rootValue = preorder[left];
    // Find the location of the root in inorder vector
    int dis = find(inorder.begin()+i, inorder.begin()+j, rootValue) - (inorder.begin() + i);
    // Assign the current node
    TreeNode* root = new TreeNode(rootValue);
    // Partition the left sub-tree
    root->left = Helper(preorder, left+1, left+dis, inorder, i, i+dis);
    // Partition the right sub-tree
    root->right = Helper(preorder, left+1+dis, right, inorder, i+dis+1, j);
    
    return root;
                         
    }
};

/*  Pretty smart and fast iterative solution, hard to understand

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())    return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode *> s;
        s.push(root);
        int ind = 0;
        for(int i = 1; i < preorder.size(); i++) {
            TreeNode *cur = s.top();
            if(s.top()->val != inorder[ind]) {
                cur->left = new TreeNode(preorder[i]);
                s.push(cur->left);
            }
           else {
                while(!s.empty() && s.top()->val == inorder[ind]){
                    cur = s.top();
                    s.pop();
                    ind++;
                }
                if (ind < inorder.size()) {
                    cur->right = new TreeNode(preorder[i]);
                    s.push(cur->right);
                }
            }
        }
        return root;
    }
    
*/
