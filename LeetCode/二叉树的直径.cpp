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

    int treelength(TreeNode* root,int &ans){
        if(!root) return -1;
        int left=treelength(root->left,ans)+1;
        int right=treelength(root->right,ans)+1;
        ans=max(ans,left+right);
        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        treelength(root,ans);
        return ans;
    }
};