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
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(!root) return 0;
        int curr = (root->left && !root->left->left && !root->left->right)?root->left->val:0; 
        int l = sumOfLeftLeaves(root->left);
        int r = sumOfLeftLeaves(root->right);
        return  curr + l + r;
    }
};