/*

82. Remove Duplicates from Sorted List II 

Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.


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

ListNode* deleteDuplicates(ListNode* head) {

        if(!head || !head->next)
            return head;
        
        ListNode newhead(head->val-1);
        newhead.next = head;
        
        ListNode *pre = &newhead, *cur = head;
    
        while(cur && cur->next)
        {
            if(cur->val == cur->next->val )
            {
                int curval = cur->val;
                while(cur && cur->val == curval)
                    cur = cur->next;
                pre->next = cur;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return newhead.next;
        
    }
    
};


/*  recursively:

 ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        int val = head->val;
        ListNode* next = head->next;
        if( val != next->val )
        {
            head->next = deleteDuplicates(next);
            return head;
        }
        else
        {
            while(next && next->val == val)
                next = next->next;
            return deleteDuplicates(next);
        }
        
    }

*/