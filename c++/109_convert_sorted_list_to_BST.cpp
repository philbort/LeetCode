/*

109. Convert Sorted List to Binary Search Tree 

Given a singly linked list where elements are sorted in ascending order,
convert it to a height balanced BST.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        return Helper(head, NULL);
    }
    
private:
    TreeNode* Helper(ListNode* head, ListNode* tail) {
        if (head == tail)
            return NULL;
        ListNode *mid = head, *tmp = head;
        /* Use a tracked tail to find the mid is faster 
           than counting the mid every time like question 108
        */
        while(tmp != tail && tmp->next != tail)
        {
            mid = mid->next;
            tmp = tmp->next->next;
        }
        TreeNode* root = new TreeNode(mid->val);
        root->left = Helper(head, mid);
        root->right = Helper(mid->next,tail);
        return root;
        
    }
};
