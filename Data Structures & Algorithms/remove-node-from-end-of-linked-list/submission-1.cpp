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

        // advance front by n steps so front is n steps ahead of back
        // when front reaches the last node, back will be right before the target
        ListNode *front = dummy, *back = dummy;
        for (int i = 0; i < n; i++) {
            front = front->next;
        }

        // move both pointers until front reaches the last node
        while (front->next != nullptr) {
            front = front->next;
            back = back->next;
        }

        // remove the target node by skipping over it
        back->next = back->next->next;

        return dummy->next;
    }
};
