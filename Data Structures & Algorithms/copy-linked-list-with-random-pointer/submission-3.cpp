/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // step 1: interleave copied nodes after each original node
        // 1 -> 1' -> 2 -> 2' -> 3 -> 3'
        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }

        // step 2: set random pointers for copied nodes
        // cur->random->next is the copy of cur->random
        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        // step 3: separate the two lists
        cur = head;
        Node* dummy = new Node(0);
        Node* copy = dummy;
        while (cur) {
            copy->next = cur->next;     // extract copied node
            cur->next = cur->next->next; // restore original list
            copy = copy->next;
            cur = cur->next;
        }

        return dummy->next;
    }
};
