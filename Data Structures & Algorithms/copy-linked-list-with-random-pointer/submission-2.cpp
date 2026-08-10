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
    unordered_map<Node*, Node*> map;

    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* copy = new Node(head->val);
        // store current node's mapping before recursing,
        // so it's available when earlier nodes look it up via random pointers
        map[head] = copy;

        // recursively copy the rest of the list via next pointers
        // this ensures all nodes are created before we assign random pointers
        copy->next = copyRandomList(head->next);

        // by the time we reach here, all nodes reachable via next are already in the map
        // so map[head->random] is guaranteed to exist (or null if random is nullptr)
        copy->random = map[head->random];

        return copy;
    }
};