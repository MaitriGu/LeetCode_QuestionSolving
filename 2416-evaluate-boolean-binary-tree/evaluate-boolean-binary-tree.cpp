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
    bool evaluateTree(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            // Handles the case for leaf nodes.
            return root->val;
        }

        // Store the evaluations for the left subtree and right subtree.
        bool evaluateLeftSubtree = evaluateTree(root->left);
        bool evaluateRightSubtree = evaluateTree(root->right);
        bool evaluateRoot;
        if (root->val == 2) {
            evaluateRoot = evaluateLeftSubtree | evaluateRightSubtree;
        } else {
            evaluateRoot = evaluateLeftSubtree & evaluateRightSubtree;
        }

        return evaluateRoot;
    }
};