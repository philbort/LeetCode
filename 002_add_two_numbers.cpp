/*

2. Add Two Numbers

You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if( !l1 )   return l2;
        if( !l2 )   return l1;
            
        ListNode *head = new ListNode(0);
        ListNode *tmp = head;
        int carry = 0;
        
        while( l1 || l2 || carry)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            tmp->next = new ListNode(sum%10);
            tmp = tmp->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return head->next;
    }
};

