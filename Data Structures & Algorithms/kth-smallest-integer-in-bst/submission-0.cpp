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

    void kthHelper(TreeNode* node, int k){
        // Base case
        if(!node || count > k)
            return;
        
        kthHelper(node->left, k);
        if(++count == k)
            res = node->val;
        kthHelper(node->right, k);
        
        return;
    }
};
