class Solution {
public:
    vector<string> ans;

    void dfs(TreeNode* node, string path) {
        if (!node) return;

        path += to_string(node->val);

        // Leaf node
        if (!node->left && !node->right) {
            ans.push_back(path);
            return;
        }

        path += "->";

        dfs(node->left, path);
        dfs(node->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};