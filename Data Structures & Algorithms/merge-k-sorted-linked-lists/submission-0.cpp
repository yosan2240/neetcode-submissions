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
    struct Cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;

        for(ListNode* head : lists) {
            if(head)
                pq.push(head);
        }
        
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        while(!pq.empty()) {
            ListNode* node = pq.top();
            cur->next = node;
            cur = cur->next;
            pq.pop();

            if(node->next){
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};
