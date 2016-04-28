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
    // Iterative
    ListNode* reverseList(ListNode* head) {
        struct ListNode *current, *prev, *next;
        current = head;
        prev = NULL;
        next = NULL;
        while (current)
        {
            next = current->next;
            current->next = prev; 
            prev = current; 
            current = next;
        }
        return prev;
    }

/*    
    // Recursive
    ListNode* reverseList(ListNode* head) {
        if ( !head || !(head->next) )
            return head;
        ListNode* current = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return current;
    }
*/
};