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
    int postIdx;

    TreeNode* solve(vector<int>& inorder,
                    vector<int>& postorder,
                    int inStart,
                    int inEnd) {

        if (inStart > inEnd)
            return NULL;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int rootIndex = mp[rootVal];

        // Build right subtree first
        root->right = solve(inorder,
                            postorder,
                            rootIndex + 1,
                            inEnd);

        root->left = solve(inorder,
                           postorder,
                           inStart,
                           rootIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        postIdx = postorder.size() - 1;

        return solve(inorder,
                     postorder,
                     0,
                     inorder.size() - 1);
    }
};