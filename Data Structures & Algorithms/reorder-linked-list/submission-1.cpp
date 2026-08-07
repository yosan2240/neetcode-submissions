class Solution {
public:
    void reorderList(ListNode* head) {
        // step 1: find the midpoint using slow/fast pointers
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // step 2: split into two halves and reverse the second half
        ListNode *cur = slow->next;
        slow->next = nullptr;           // cut the list at the midpoint
        ListNode *next, *prev = nullptr;
        while (cur) {                   // reverse second half in-place
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // step 3: merge two halves alternately
        ListNode *tail = prev;          // tail is the head of reversed second half
        while (tail) {
            next = head->next;
            head->next = tail;          // insert tail node after head
            head = next;

            next = tail->next;
            tail->next = head;          // re-link tail to next head
            tail = next;
        }
    }
};