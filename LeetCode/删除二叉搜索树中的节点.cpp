/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        }
        if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root; 
        }
        if(!root->left){
            TreeNode* tmp = root->right;
            delete(root);
            return tmp;
        }
        if(!root->right){
            TreeNode* tmp = root->left;
            delete(root);
            return tmp;
        }
        TreeNode* tmp = root->right;
        while(tmp->left) tmp = tmp->left;
        swap(root->val, tmp->val);
        root->right = deleteNode(root->right, key);
        return root;
    }
};