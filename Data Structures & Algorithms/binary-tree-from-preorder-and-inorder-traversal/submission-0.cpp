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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Base case: empty arrays
        if (preorder.empty()) return nullptr;

        // Root is always the first element of preorder
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);

        // Find root in inorder → splits left and right
        int mid = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();
        int leftSize = mid;

        // Slice arrays for left and right subtrees
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + leftSize);
        vector<int> rightPre(preorder.begin() + 1 + leftSize, preorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin() + mid);
        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());

        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);

        return root;
    }
};

// Time:  O(n²) — linear search at each node
// Space: O(n²) — new vectors created at each level
