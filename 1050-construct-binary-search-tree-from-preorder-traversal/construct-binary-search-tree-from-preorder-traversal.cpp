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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if(n == 0) return nullptr;
        
        TreeNode *newRoot = new TreeNode(preorder[0]);  
        
        for(int i = 1; i < n; i++){
            TreeNode *temp = new TreeNode(preorder[i]);
            TreeNode *curr = newRoot;
            

            while(true){
                if(temp->val < curr->val){
                    if(curr->left == nullptr){
                        curr->left = temp; 
                        break;
                    }
                    curr = curr->left;  
                }
                else{ 
                    if(curr->right == nullptr){
                        curr->right = temp;  
                        break;
                    }
                    curr = curr->right;  
                }
            }
        }
        
        return newRoot;
    }
};