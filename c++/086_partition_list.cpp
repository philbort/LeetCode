/*

86. Partition List

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next)   return head;
        ListNode dummy1(0), dummy2(0);
        ListNode *small = &dummy1, *large = &dummy2;

        while(head){
            if(head->val < x){
                small->next = head;
                small = small->next;
            }
            else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = NULL;
        small->next = dummy2.next;
        return dummy1.next;
    }
};


/*   Use a queue to save all the bigger values in order
     linear time complexity but space complexity is bad

    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next)   return head;
        queue<int> list;
        ListNode *slow =head, *fast = head;
        while(fast){
            if(fast->val >= x){
                list.push(fast->val);
            }
            else {
                slow->val = fast->val;
                slow = slow->next;
            }
            fast = fast->next;
        }
        while(!list.empty()){
            slow->val = list.front();
            list.pop();
            slow = slow->next;
        }
        return head;
    }
*/
