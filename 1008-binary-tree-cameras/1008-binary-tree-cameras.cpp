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
class Solution 
{
public:
    int solve(TreeNode* root,int &c)
    {
        if(root == NULL)    return 1;
        int l = solve (root->left,c);
        int r = solve (root->right,c);
        if(l==0 || r==0)    {c++;return 2;}
        if(l==2 || r==2)    return 1;
        return 0;
    }
    int minCameraCover(TreeNode* root) 
    {
        int c=0;
        return (solve(root,c) == 0) ? c+1 : c;
    }
};