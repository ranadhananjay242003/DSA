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

    bool isBST(TreeNode* root, long long min_val, long long max_val) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= min_val || root->val >= max_val) {
            return false;
        }

        return isBST(root->left, min_val, root->val) && isBST(root->right, root->val, max_val);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, LLONG_MIN, LLONG_MAX);
    }
};