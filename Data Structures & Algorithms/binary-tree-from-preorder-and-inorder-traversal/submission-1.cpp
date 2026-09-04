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
    unordered_map<int, int> table;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Precompute value → index for inorder
        for (int i = 0; i < inorder.size(); i++)
            table[inorder[i]] = i;

        return helper(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, int inStart, int inEnd) {
        // Base case: empty range
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        // Root is always the first element of current preorder range
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // Find root in inorder → splits left and right subtrees
        int mid = table[rootVal];
        int leftSize = mid - inStart;

        // Recurse on left subtree
        root->left = helper(preorder, preStart + 1, preStart + leftSize, inStart, mid - 1);

        // Recurse on right subtree
        root->right = helper(preorder, preStart + leftSize + 1, preEnd, mid + 1, inEnd);

        return root;
    }
};

// Time: O(n) — O(n) to build the hashmap, each node visited once with O(1) lookup
// Space: O(n) — O(n) for the hashmap, O(h) for the call stack, overall O(n)