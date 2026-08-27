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
    int diameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        diameterHelper(root);
        return diameter;
    }

    // Returns height of subtree rooted at root,
    // while updating the global diameter at each node
    int diameterHelper(TreeNode* root) {
        // Base case: empty node contributes 0 height
        if (!root)
            return 0;

        int left_height = diameterHelper(root->left);
        int right_height = diameterHelper(root->right);

        // Longest path through this node = left height + right height
        diameter = max(left_height + right_height, diameter);

        // Return height of this subtree to parent
        return max(left_height, right_height) + 1;
    }
};

// Time:  O(n) — every node visited once
// Space: O(h) — call stack depth equals tree height
//        O(n) worst case (skewed), O(log n) for balanced
