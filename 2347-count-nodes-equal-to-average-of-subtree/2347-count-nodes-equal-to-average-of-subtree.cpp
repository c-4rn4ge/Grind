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
    pair<int, int> postOrder(TreeNode* r, int &ans) 
    {
        if (r == NULL) return {0, 0};
        pair<int, int> i = postOrder(r->left, ans);
        pair<int, int> j = postOrder(r->right, ans);
        int sum = i.first + j.first + r->val;
        int count = i.second + j.second + 1;
        if (r->val == sum / (count))     ans++;
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* r) 
    {
        int ans = 0;
        postOrder(r,ans);
        return ans;
    }
};
