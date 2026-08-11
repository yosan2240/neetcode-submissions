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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addHelper(l1, l2, 0);
    }

    ListNode* addHelper(ListNode* l1, ListNode* l2, int carry) {
        // base case: both lists exhausted and no carry left
        if (!l1 && !l2 && carry == 0) return nullptr;

        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;
        int sum = val1 + val2 + carry;

        // create new node with the current digit
        ListNode* newNode = new ListNode(sum % 10);

        // connect to the rest of the result list recursively
        newNode->next = addHelper(l1 ? l1->next : nullptr,
                                  l2 ? l2->next : nullptr,
                                  sum / 10);
        return newNode;
    }
};
