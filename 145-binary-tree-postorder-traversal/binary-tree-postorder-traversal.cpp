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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postOrderHelper(root,result);
        return result;
    }
private:
    void postOrderHelper(TreeNode* root, vector<int> &result){
        if(root==nullptr){
            return;
        }
        postOrderHelper(root->left,result);
        postOrderHelper(root->right,result);
        result.push_back(root->val);
    }
};