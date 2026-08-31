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
    int goodNodes(TreeNode* root) {
        int maxSoFar = root->val;
        return helper(root->left, maxSoFar) + helper(root->right, maxSoFar) + 1;;
    }

    int helper(TreeNode* node, int maxSoFar){
        //base case
        if(!node)
            return 0;
        
        //recursion
        if(node->val >= maxSoFar){
            maxSoFar = node->val;
            return helper(node->left, maxSoFar) + helper(node->right, maxSoFar) + 1;
        }
        else{
            return helper(node->left, maxSoFar) + helper(node->right, maxSoFar);
        }
    }
};
