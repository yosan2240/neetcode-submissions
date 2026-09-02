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
    int count = 0;
    int res;

    int kthSmallest(TreeNode* root, int k) {
        kthHelper(root, k);
        return res;
    }

    void kthHelper(TreeNode* node, int k) {
        // Base case: null node or already found the answer
        if (!node || count >= k)
            return;

        // In-order traversal: left → current → right
        // Gives nodes in ascending order for BST
        kthHelper(node->left, k);

        // Process current node: increment count and check if it's the kth
        if (++count == k)
            res = node->val;

        kthHelper(node->right, k);
    }
};

// Time:  O(h + k) — traverse down to leftmost node O(h), then count k nodes
// Space: O(h) — call stack depth equals tree height
//        O(log n) for balanced tree, O(n) worst case (skewed)