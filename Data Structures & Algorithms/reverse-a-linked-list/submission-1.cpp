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
    ListNode* reverseList(ListNode* head) {
        // track previous, current, and next nodes to avoid losing references
        ListNode *prev = NULL, *cur, *next;

        cur = head;
        while(cur) {
            // save next, reverse the pointer, then advance both pointers
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // prev is now the new head of the reversed list
        return prev;
    }
};
