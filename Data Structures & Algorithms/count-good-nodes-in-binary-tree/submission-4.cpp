class Solution {
public:
    int goodNodes(TreeNode* root) {
        // Use INT_MIN so root is always counted as a good node
        return helper(root, INT_MIN);
    }

    int helper(TreeNode* node, int maxSoFar) {
        // Base case: null node contributes 0 good nodes
        if (!node)
            return 0;

        // Update max value seen along the path from root to current node
        int newMax = max(maxSoFar, node->val);

        // Count left and right subtree good nodes
        int count = helper(node->left, newMax) + helper(node->right, newMax);

        // Current node is good if its value >= max along path from root
        if (node->val >= maxSoFar)
            count++;

        return count;
    }
};

// Time:  O(n) — every node visited once
// Space: O(h) — call stack depth equals tree height
//        O(log n) for balanced tree, O(n) worst case (skewed)