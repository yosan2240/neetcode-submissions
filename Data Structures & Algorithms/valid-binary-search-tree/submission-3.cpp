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
    bool isValidBST(TreeNode* root) {
        // Start with no constraints on the root
        return isValidHelper(root, LONG_MIN, LONG_MAX);
    }

    bool isValidHelper(TreeNode* root, long minimum, long maximum) {
        // Base case: null node is always valid
        if (!root)
            return true;

        // Current node must strictly fall within inherited bounds
        if (root->val <= minimum || root->val >= maximum)
            return false;

        // Left subtree: upper bound tightens to current node's value
        // Right subtree: lower bound tightens to current node's value
        return isValidHelper(root->left, minimum, root->val) &&
               isValidHelper(root->right, root->val, maximum);
    }
};

// Time:  O(n) — every node visited once
// Space: O(h) — call stack depth equals tree height
//        O(log n) for balanced tree, O(n) worst case (skewed)
