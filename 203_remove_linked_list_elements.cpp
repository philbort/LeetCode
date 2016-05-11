/*

203. Remove Linked List Elements

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {

public:
	
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return NULL;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};

/*  iterative:

    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return NULL;
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* tmp = newhead;
        while(tmp) {
            if(tmp->next && tmp->next->val == val)
                tmp->next = tmp->next->next;
            else tmp = tmp->next;
        }
        return newhead->next;
    }
*/