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
    TreeNode* invertTree(TreeNode* root) {
        // Base case: empty node, nothing to invert
        if (root == nullptr)
            return nullptr;

        // Recursively invert left and right subtrees,
        // then swap them at the current node
        TreeNode* temp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = temp;

        return root;
    }
};

// Time:  O(k) — every node is visited exactly once
// Space: O(h) — call stack depth equals tree height
//        O(k) worst case (skewed tree), O(log k) for balanced tree