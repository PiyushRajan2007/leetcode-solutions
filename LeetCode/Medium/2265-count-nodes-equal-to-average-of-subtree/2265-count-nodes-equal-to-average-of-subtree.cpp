class Solution {
public:
    int cnt = 0;

    pair<int, int> count(TreeNode* root) {
        if (!root)
            return {0, 0};

        auto left = count(root->left);
        auto right = count(root->right);

        int sum = root->val + left.first + right.first;
        int nodes = 1 + left.second + right.second;

        if (root->val == sum / nodes)
            cnt++;

        return {sum, nodes};
    }

    int averageOfSubtree(TreeNode* root) {
        count(root);
        return cnt;
    }
};