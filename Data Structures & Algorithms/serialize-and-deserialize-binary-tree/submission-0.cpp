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

class Codec {
public:
    
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        sHelper(root, result);
        return result;
    }

    void sHelper(TreeNode* node, string& result) {
        if (!node) {
            result += "N,";
            return;
        }
        result += to_string(node->val) + ",";
        sHelper(node->left, result);
        sHelper(node->right, result);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> tokens;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            tokens.push(token);
        }

        return dHelper(tokens);
    }

    TreeNode* dHelper(queue<string>& tokens) {
        string token = tokens.front(); 
        tokens.pop();
        if(token == "N")
            return nullptr;
        TreeNode* node = new TreeNode(stoi(token));
        node->left = dHelper(tokens);
        node->right = dHelper(tokens);

        return node;
    }
};