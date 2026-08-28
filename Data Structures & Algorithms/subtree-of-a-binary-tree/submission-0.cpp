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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Base case: exhausted main tree without finding a match
        if (root == nullptr)
            return false;

        // Check if current node is the root of a matching subtree
        if (isSameTree(root, subRoot))
            return true;

        // Otherwise search deeper in left and right subtrees
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both null → identical at this position
        if (p == nullptr && q == nullptr)
            return true;
        // One null, one not → structure differs
        if (p == nullptr || q == nullptr)
            return false;
        // Values differ → not the same
        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Time:  O(n * m) — isSameTree called at each of n nodes, costs O(m) each
// Space: O(h + H) — isSubtree and isSameTree stacks coexist at the same time
//        h = height of main tree, H = height of subRoot tree
