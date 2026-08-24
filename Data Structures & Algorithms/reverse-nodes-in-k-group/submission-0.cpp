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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev, *next, *prevList, *cur;

        // Use dummy node to avoid edge case for the first node
        ListNode* dummy = new ListNode();
        dummy->next = head;
        prevList = dummy;
        prev = NULL;

        while(head) {
            // walk k steps to verify
            cur = head;
            int count = k;
            while(count && cur != nullptr) {
                cur = cur->next;
                count--;
            }
            // if not enough nodes, break
            if(count)  
                break;
            // reverse the k nodes group 
            cur = head;
            for (int i = 0; i < k; i++) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            // reconnect
            // prev = new head, head = new tail
            prevList->next = prev;
            head->next = cur;

            // move prevList
            prevList = head;
            head = cur;
        }

        return dummy->next;
    }
};
