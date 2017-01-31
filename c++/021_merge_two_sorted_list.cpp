/*

21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

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
    // Time: O(n)
    // Space: O(1)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode *newhead = new ListNode(0);
        ListNode *head = newhead;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                head->next = l1;
                l1 = l1->next;
            }
            else
            {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        if(!l1)
            head->next = l2;
        if(!l2)
            head->next = l1;
        return newhead->next;
    }
};

/*
class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};
*/
