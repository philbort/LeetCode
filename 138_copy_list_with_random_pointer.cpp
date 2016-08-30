/*

138. Copy List with Random Pointer

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

*/

class Solution {
    
public:

    // O(n) time and O(1) space solution
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)   return NULL;
        RandomListNode *newHead = NULL;
        // Pointer to the nodes in the original list
        RandomListNode *orig_ptr = head; 
        // Pointer the the nodes in the copy list
        RandomListNode *copy_ptr = NULL;
        
        // Duplicate the nodes in the original list
        while (orig_ptr)
        {
            copy_ptr = new RandomListNode (orig_ptr->label);
            copy_ptr->next = orig_ptr->next;
            orig_ptr->next = copy_ptr;
            orig_ptr = copy_ptr->next;
        }
        
        // Link the random nodes
        orig_ptr = head;
        while (orig_ptr)
        {
            copy_ptr = orig_ptr->next;
            if (orig_ptr->random)
                copy_ptr->random = orig_ptr->random->next;
            orig_ptr = copy_ptr->next;
        }
        
        // Remove the links between original and copy lists
        orig_ptr = head;
        newHead = head->next;
        while (orig_ptr)
        {
            copy_ptr = orig_ptr->next;
            orig_ptr->next = copy_ptr->next;
            orig_ptr = orig_ptr->next;
            if (orig_ptr)
                copy_ptr->next = orig_ptr->next;
        }
        return newHead;
    }

};


/*  DFS and BFS solutions similar to clone graph:


    DFS solution:

    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)   return NULL;
        if(map.find(head) == map.end()) {
            map[head] = new RandomListNode(head->label);
            map[head]->next = copyRandomList(head->next);
            map[head]->random = copyRandomList(head->random);
        }
        return map[head];
    }



    // BFS solution:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)   return NULL;
        // Queue for all the nodes
        queue<RandomListNode*> toVisit;
        map[head] = new RandomListNode(head->label);
        toVisit.push(head);
        while(!toVisit.empty()) {
            RandomListNode *current = toVisit.front();
            toVisit.pop();
            // If we haven't created the next node
            if(current->next && map.find(current->next) == map.end()) {
                // Create the next node
                map[current->next] = new RandomListNode(current->next->label);
                // Add it to the queue
                toVisit.push(current->next);
            }
            // If we haven't created the random node
            if(current->random && map.find(current->random) == map.end()) {
                // Create the random node
                map[current->random] = new RandomListNode(current->random->label);
                // Add it to the queue
                toVisit.push(current->random);
            }
            // link the next and random nodes to the current node
            map[current]->next = map[current->next];
            map[current]->random = map[current->random];
        }
        return map[head];
    }
private:
    unordered_map<RandomListNode*, RandomListNode*> map;

*/