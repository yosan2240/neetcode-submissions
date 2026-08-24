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
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode* prevList = dummy;


        while (head != nullptr) {
            // Walk k steps to verify at least k nodes remain
            // curr lands on the remaining list pointer after the loop
            ListNode* curr = head;
            int count = 0;
            while (count < k && curr != nullptr) {
                curr = curr->next;
                count++;
            }
            if (count < k) break;

            // Reverse k nodes starting from head
            ListNode* prev = nullptr;
            curr = head;
            for (int i = 0; i < k; i++) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // prev = new head, head = new tail, curr = the head of remaining list
            prevList->next = prev;  // connect prevList to new head
            head->next = curr;       // connect new tail to remaining list

            // Advance prevList to new tail for next iteration
            prevList = head;
            head = curr;
        }

        return dummy->next;
    }
};
