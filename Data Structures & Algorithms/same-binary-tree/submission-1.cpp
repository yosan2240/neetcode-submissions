/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: both null → identical at this position
        if (p == nullptr && q == nullptr)
            return true;
        // One null, one not → structure differs
        else if (p && q == nullptr || p == nullptr && q)
            return false;

        // Values differ → not the same
        if (p->val != q->val)
            return false;

        // Recursively check left and right subtrees
        if (!isSameTree(p->left, q->left))
            return false;
        if (!isSameTree(p->right, q->right))
            return false;

        return true;
    }
};

// Time:  O(n) — visits each node pair once
// Space: O(h) — call stack depth equals tree height