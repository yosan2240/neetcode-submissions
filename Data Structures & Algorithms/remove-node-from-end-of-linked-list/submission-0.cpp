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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // dummy node handles the edge case where the head itself needs to be removed
        ListNode *dummy = new ListNode();
        dummy->next = head;

        // Move the front pointer before the back pointer
        // so the two pointer are n-1 steps apart.
        ListNode *front = dummy, *back = dummy;
        for(int i = 0; i < n; i++) {
            front = front->next;
        }

        while(front->next != nullptr) {
            front = front->next;
            back = back->next;
        }

        back->next = back->next->next;



        return dummy->next;
    }
};
