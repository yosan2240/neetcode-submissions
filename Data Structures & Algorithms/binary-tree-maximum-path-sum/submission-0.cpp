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
    int maximum = INT_MIN;

    int maxPathSum(TreeNode* root) {
        helper(root);
        return maximum;
    }

    int helper(TreeNode* node) {
        // Base case: null node contributes 0
        if (!node) return 0;

        // Ignore negative contributions from subtrees
        int left_gain = max(helper(node->left), 0);
        int right_gain = max(helper(node->right), 0);

        // Update global maximum with best path through current node
        maximum = max(maximum, left_gain + right_gain + node->val);

        // Return best single-direction path to parent
        return node->val + max(left_gain, right_gain);
    }
};

// Time:  O(n) — every node visited once
// Space: O(h) — call stack depth equals tree height