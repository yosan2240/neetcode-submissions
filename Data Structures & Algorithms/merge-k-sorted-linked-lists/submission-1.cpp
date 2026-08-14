/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // min-heap ordered by node value
    struct Cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
      
        // initialize heap with the head of each non-empty list
        for(ListNode* head : lists) {
            if(head)
                pq.push(head);
        }
        
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        // repeatedly extract the smallest node and advance its list
        while(!pq.empty()) {
            ListNode* node = pq.top();
            cur->next = node;
            cur = cur->next;
            // pop the node after merging it into the result list
            pq.pop();

            // push the next node from the same list if it exists
            if(node->next){
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};
