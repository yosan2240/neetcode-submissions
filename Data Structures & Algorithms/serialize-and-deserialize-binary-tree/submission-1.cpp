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
    // Encodes a tree to a single string using preorder DFS.
    // Null nodes are recorded as "N," to preserve structure.
    string serialize(TreeNode* root) {
        string result = "";
        sHelper(root, result);
        return result;
    }

    void sHelper(TreeNode* node, string& result) {
        // Base case: null node → record as "N,"
        if (!node) {
            result += "N,";
            return;
        }
        // Record current node value, then recurse left and right
        result += to_string(node->val) + ",";
        sHelper(node->left, result);
        sHelper(node->right, result);
    }

    // Decodes the encoded string back to a binary tree.
    TreeNode* deserialize(string data) {
        // Split serialized string into tokens by ','
        queue<string> tokens;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            tokens.push(token);
        }
        return dHelper(tokens);
    }

    TreeNode* dHelper(queue<string>& tokens) {
        // Consume the next token
        string token = tokens.front();
        tokens.pop();

        // Base case: "N" means null node
        if (token == "N")
            return nullptr;

        // Build current node, then recursively build left and right subtrees
        TreeNode* node = new TreeNode(stoi(token));
        node->left = dHelper(tokens);
        node->right = dHelper(tokens);

        return node;
    }
};

// Time:  O(n) — every node visited once for both serialize and deserialize
// Space: O(n) — result string and tokens queue both store n nodes