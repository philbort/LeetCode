/*

106. Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.

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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return Helper( inorder, 0, inorder.size()-1, 
                       postorder, 0, postorder.size()-1 );
    }

private:

    TreeNode* Helper(vector<int>& inorder, int left, int right,
                     vector<int>& postorder, int i, int j) 
    {
    if (left > right || i > j)
        return NULL;
    // The last element in the current postorder vector is the current node
    int rootValue = postorder[j];
    // Find the location of the root in inorder vector
    int dis = find(inorder.begin()+left, inorder.begin()+right, rootValue) - (inorder.begin() + left);
    // Assign the current node
    TreeNode* root = new TreeNode(rootValue);
    // Partition the left sub-tree
    root->left = Helper(inorder, left, left+dis-1, postorder, i, i+dis-1);
    // Partition the right sub-tree
    root->right = Helper(inorder, left+dis+1, right, postorder, i+dis, j-1);
    
    return root;
                         
    }
};

/*  Iterative solution:

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0)return NULL;
        TreeNode* p;
        TreeNode* root;
        vector<int> vint;
        vector<TreeNode*> vtn;
        root = new TreeNode(postorder.back());
        vtn.push_back(root);
        postorder.pop_back();
        while(true)
        {
            if(inorder.back() == vtn.back()->val)
            {
                p = vtn.back();
                vtn.pop_back();
                inorder.pop_back();
                if(inorder.size() == 0) break;
                if(vtn.size())
                    if(inorder.back() == vtn.back()->val)continue;
                p->left = new TreeNode(postorder.back());
                postorder.pop_back();
                vtn.push_back(p->left);
            }
            else
            {
                p = new TreeNode(postorder.back());
                postorder.pop_back();
                vtn.back()->right = p;
                vtn.push_back(p);
            }
        }
        return root;
    }
    
*/

