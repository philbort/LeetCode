/*

142. Linked List Cycle II

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

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
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        ListNode *slow = head, *fast = head, *result = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                while(slow != result)
                {
                    slow = slow->next;
                    result = result->next;
                }
                return result;
            }
        }
        return NULL;
    }
};
