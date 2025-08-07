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
void inorder(TreeNode* root, vector<int> &in){
    if(root == nullptr){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);

}
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderval;
        int target = k;
        inorder(root, inorderval);
        int i =0, j = inorderval.size()-1;
        while(i<j){
            int sum = inorderval[i] + inorderval[j];
            if(sum == target){
                return true;
            }
            else if(sum>target){
                j--;
            }
            else if(sum<target){
                i++;
            }
            else{
                return false;
            }
        }
        return 0;
    }
};