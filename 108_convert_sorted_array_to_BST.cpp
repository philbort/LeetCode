/*

108. Convert Sorted Array to Binary Search Tree 

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Helper(nums, 0, nums.size());
    }
    
private:
    // With a helper to pass the index, we can avoid allocate new array
    TreeNode* Helper(vector<int>& nums, int start, int end) {
        if( end <= start )
            return NULL;
        int mid = start + (end - start)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = Helper(nums,start,mid);
        root->right = Helper(nums,mid+1,end);
        return root;
    }
};