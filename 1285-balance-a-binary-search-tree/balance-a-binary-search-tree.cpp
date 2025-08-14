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
    void inorder(TreeNode *root, vector<int> &in){
        if(root == nullptr){
            return;
        }
        inorder(root -> left, in);
        in.push_back(root->val);
        inorder(root->right, in);

    }

    TreeNode* inorderToBST(int s, int e, vector<int> &in){
        if(s>e){
            return nullptr;
        }
        int mid = (s + e )/ 2;
        TreeNode* newRoot = new TreeNode(in[mid]);
        newRoot->left = inorderToBST(s, mid - 1, in);
        newRoot->right = inorderToBST(mid + 1, e, in);
        return newRoot;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderVal;
        inorder(root, inorderVal);
        return inorderToBST(0 , inorderVal.size() - 1, inorderVal);
    }
};