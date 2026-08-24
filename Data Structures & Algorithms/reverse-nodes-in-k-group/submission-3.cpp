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
    // Using recursion cause the space complexity to O(n), so the optimal is iteration, not this one  
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base case: walk k steps to verify enough nodes remain
        // curr lands on the remaining list pointer for free
        ListNode* curr = head;
        int count = 0;
        while (count < k && curr != nullptr) {
            curr = curr->next;
            count++;
        }
        if (count < k) return head;  // fewer than k nodes, leave unchanged

        // Reverse k nodes starting from head
        ListNode* prev = nullptr;
        curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // prev = new head of reversed group
        // head = new tail of reversed group
        // curr = start of remaining list

        // Connect tail to recursively processed remaining list
        head->next = reverseKGroup(curr, k);

        return prev;  // new head of this group
    }
};
