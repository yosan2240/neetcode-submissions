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
    bool isBalanced(TreeNode* root) {
        return heightHelper(root) != -1;
    }

    // Returns height of subtree, or -1 if unbalanced
    int heightHelper(TreeNode* root) {
        // Base case: empty node has height 0
        if (!root)
            return 0;

        int left_height = heightHelper(root->left);
        if (left_height == -1) return -1;  // early exit

        int right_height = heightHelper(root->right);
        if (right_height == -1) return -1;  // early exit

        // If height difference > 1, signal unbalanced upward
        if (abs(left_height - right_height) > 1)
            return -1;

        return max(left_height, right_height) + 1;
    }
};

// Time:  O(n) — every node visited once (short-circuits on unbalanced)
// Space: O(h) — call stack depth equals tree height