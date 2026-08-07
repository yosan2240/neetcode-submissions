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
    void reorderList(ListNode* head) {
        // Use slow and fast pointers to find the midpoint
        ListNode *fast = head, *slow = head;
        
        // slow will be the midpoint after the iteration
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the link-list into two halves, and reverse the second half
        ListNode *cur = slow->next;
        // cut the link-list into two halves
        slow->next = nullptr;
        ListNode *next, *prev = nullptr;

        // "prev" will be the pointer of the last node after iteration
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        ListNode *tail = prev;

        // Start redirecting the pointer according to the rule 
        while(tail) {
            next = head->next;
            head->next = tail;
            head = next;
            
            next = tail->next;
            tail->next = head;
            tail = next;
        }
    }
};
