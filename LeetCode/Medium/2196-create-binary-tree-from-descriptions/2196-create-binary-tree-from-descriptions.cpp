/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Maps node value to the actual TreeNode pointer
        unordered_map<int, TreeNode*> nodeMap;
        // Stores all values that are children
        unordered_set<int> children;

        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            bool isLeft = desc[2] == 1;

            // Create parent node if it doesn't exist
            if (nodeMap.find(parentVal) == nodeMap.end()) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }
            // Create child node if it doesn't exist
            if (nodeMap.find(childVal) == nodeMap.end()) {
                nodeMap[childVal] = new TreeNode(childVal);
            }

            // Connect parent to child
            if (isLeft) {
                nodeMap[parentVal]->left = nodeMap[childVal];
            } else {
                nodeMap[parentVal]->right = nodeMap[childVal];
            }

            // Mark this node as a child
            children.insert(childVal);
        }

        // The root is the parent node that is never a child
        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            if (children.find(parentVal) == children.end()) {
                return nodeMap[parentVal];
            }
        }

        return nullptr;
    }
};