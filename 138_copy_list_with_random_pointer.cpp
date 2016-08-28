/*

138. Copy List with Random Pointer

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

*/

class Solution {
public:
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
};

/* DFS solution:

    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)   return NULL;
        if(map.find(head) == map.end()) {
            map[head] = new RandomListNode(head->label);
            map[head]->next = copyRandomList(head->next);
            map[head]->random = copyRandomList(head->random);
        }
        return map[head];
    }

*/
