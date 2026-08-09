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
        unordered_map<Node*, Node*> table;
        Node *cur = head;
        Node *copy = new Node(0);
        Node *dummy = copy;
        // Copy the value and the next pointer on the first pass
        // to avoid the edge case where the random pointer links to a node 
        // that hasn't been built yet(no yet built)
        while(cur) {
            copy->next = new Node(cur->val);
            // Associate each original node with its copy
            table[cur] = copy->next;
            // Move to the next node
            copy = copy->next;
            cur = cur->next;
        }

        cur = head;
        copy = dummy->next;
        // Now we've built all the nodes, fill the random pointers
        while(cur) {
            Node *temp = table[cur->random];
            copy->random = temp;
            copy = copy->next;
            cur = cur->next;
        }

        return dummy->next;
    }
};
