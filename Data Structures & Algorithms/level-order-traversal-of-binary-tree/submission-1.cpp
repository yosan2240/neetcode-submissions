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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;

        // Edge case: empty tree
        if (!root)
            return res;

        q.push(root);

        while (!q.empty()) {
            // Snapshot current level size before pushing children
            int size = q.size();
            vector<int> temp(size);

            // Process exactly one level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp[i] = node->val;

                // Push children for next level
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back(temp);
        }

        return res;
    }
};

// Time:  O(n) — every node visited exactly once
// Space: O(n) — queue holds at most n/2 nodes at the widest level