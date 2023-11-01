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
    void in(TreeNode *root, vector<int> &ans)
    {
        if (root) 
        {
            ans.push_back(root->val);
            in(root->left, ans);
            in(root->right, ans);
        }
    }
    vector<int> findMode(TreeNode *root)
    {
        vector<int> v;
        in(root, v);
        unordered_map<int, int> mp;
        int maxi = 0;
        for (auto &i: v)
        {
            mp[i]++;
            maxi = max(maxi, mp[i]);
        }
        vector<int> ans;
        for (auto &i : mp)
        {
            if (i.second == maxi)    ans.push_back(i.first);
        }
        return ans;
    }
};