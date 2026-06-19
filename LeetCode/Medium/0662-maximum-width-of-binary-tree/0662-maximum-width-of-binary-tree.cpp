class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        int maxwidth = 0;

        while (!q.empty()) {
            int currLevelSize = q.size();

            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;

            maxwidth = max(maxwidth, (int)(endIdx - stIdx + 1));

            for (int i = 0; i < currLevelSize; i++) {
                auto curr = q.front();
                q.pop();

                TreeNode* node = curr.first;
                unsigned long long idx = curr.second;

                if (node->left) {
                    q.push({node->left, idx * 2 + 1});
                }

                if (node->right) {
                    q.push({node->right, idx * 2 + 2});
                }
            }
        }

        return maxwidth;
    }
};