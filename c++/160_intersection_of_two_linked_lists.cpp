/*

160. Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)
            return NULL;
        ListNode *tmpA = headA, *tmpB = headB;
        int size_a = 0, size_b = 0;
        while(tmpA)
        {
            tmpA = tmpA->next;
            size_a++;
        }
        tmpA = headA;
        while(tmpB)
        {
            tmpB = tmpB->next;
            size_b++;
        }
        tmpB = headB;
        if(size_a >= size_b)
        {
            for(int i = 0; i < size_a-size_b; i++)
                tmpA = tmpA->next;
        }
        else
        {
            for(int i = 0; i < size_b-size_a;i++)
                tmpB = tmpB->next;
        }
        while(tmpA && tmpB)
        {
            if(tmpA == tmpB)
                return tmpA;
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }
        return NULL;
    }
};
