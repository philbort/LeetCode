/*

234. Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode *slow = head, *fast = head;
        
        // find the middle point
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse the second half
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow)
        {
            if(head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    
private:
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next)
            return head;
        ListNode* current = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return current;
    }
};


/* Recursively (did not pass the time limit, but works for sure, also not O(1) space):

public:
    bool isPalindrome(ListNode* head) {
       int n = 0;
       ListNode* tmp = head;
       while(tmp)
       {
           tmp = tmp->next;
           n++;
       }
       return Helper(head,n);
    }
private:
    bool Helper(ListNode* head, int n){
        if( n < 2)
            return true;
        ListNode* tail = head;
        for(int i = 0; i < n-1; i++)
            tail = tail->next;
        return ( (head->val == tail->val) && Helper(head->next, n-2) );
    }

*/
