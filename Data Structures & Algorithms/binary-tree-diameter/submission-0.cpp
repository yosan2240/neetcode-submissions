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

    //return largest hieght
    int diameterHelper(TreeNode* root){
        //base case
        if(!root)
            return 0;

        int left_height = diameterHelper(root->left);
        int right_height = diameterHelper(root->right);

        diameter = max(left_height + right_height, diameter);

        return max(left_height, right_height) + 1;
    }
};
