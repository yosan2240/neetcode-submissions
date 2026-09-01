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
    bool isValidBST(TreeNode* root) {
        long minimum = LONG_MIN;
        long maximum = LONG_MAX;
        return isValidHelper(root, minimum, maximum);
    }

    bool isValidHelper(TreeNode* root, long minimum, long maximum){
        //base case
        if(!root)
            return true;
          
        //recursion
        if(root->val < maximum && root->val > minimum){
            if(isValidHelper(root->left, minimum, root->val) && isValidHelper(root->right, root->val, maximum))
                return true;
            return false;
        }
        else
            return false;
    }
};
