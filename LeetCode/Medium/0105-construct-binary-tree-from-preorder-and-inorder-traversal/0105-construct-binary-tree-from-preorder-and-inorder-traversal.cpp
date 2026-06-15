/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;

    TreeNode* solve(vector<int>& preorder, int preStart,
                    int inStart, int inEnd) {

        if (preStart >= preorder.size() || inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int rootIndex = mp[root->val];
        int leftSize = rootIndex - inStart;

        root->left = solve(preorder,
                           preStart + 1,
                           inStart,
                           rootIndex - 1);

        root->right = solve(preorder,
                            preStart + leftSize + 1,
                            rootIndex + 1,
                            inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder, 0, 0, inorder.size() - 1);
    }
};