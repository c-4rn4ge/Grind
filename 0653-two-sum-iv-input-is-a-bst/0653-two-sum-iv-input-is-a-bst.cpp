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
    void in(vector<int> &arr, TreeNode *root)
    {
        if(root)
        {
            in(arr,root->left);
            arr.push_back(root->val);
            in(arr,root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> arr;
        in(arr,root);int n = arr.size();
        int i = 0,j = n -1;
        while(i<n && j>0 && i<j)
        {   
            int sum = arr[i] + arr[j];
            if(sum == k) return true;
            else if(sum > k ) j--;
            else i++;
        }
        return false;
    }
};