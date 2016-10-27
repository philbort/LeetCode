/*

61. Rotate List  

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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

    ListNode* rotateRight(ListNode* head, int k) {

        if(k == 0 || !head || !head->next)
            return head;

        int n = 1;

        ListNode* tmp = head, *tmp1 = head;
        
        while( tmp->next )
        {
            tmp = tmp->next;
            n++;
        }
        
        k = k % n;
        if (k == 0)
            return head;
            
        for (int i = 0; i < n - k; i++)
            head = head->next;
            
        tmp->next = tmp1;
        
        for (int i=0; i < n - k - 1; i++)
            tmp1 = tmp1->next;
            
        tmp1->next = NULL;
        return head;
    }
};
