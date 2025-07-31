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
private:
    // Helper function to check for a valid BST within a given range.
    bool isBST(TreeNode* root, long long min_val, long long max_val) {
        // A null node is considered a valid BST.
        if (root == nullptr) {
            return true;
        }

        // The current node's value must be within the valid range.
        // If not, it's not a valid BST.
        if (root->val <= min_val || root->val >= max_val) {
            return false;
        }

        // Recursively check the left and right subtrees with updated ranges.
        // For the left subtree, the maximum value becomes the current node's value.
        // For the right subtree, the minimum value becomes the current node's value.
        return isBST(root->left, min_val, root->val) && isBST(root->right, root->val, max_val);
    }

public:
    bool isValidBST(TreeNode* root) {
        // Initial call to the helper function with the widest possible range.
        return isBST(root, LLONG_MIN, LLONG_MAX);
    }
};