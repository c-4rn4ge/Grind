/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* h1, ListNode* h2)
    {
        if (!h1)    return h2;
        if (!h2)    return h1;
        if (h1->val < h2->val) 
        {
            h1->next = merge(h1->next, h2);
            return h1;
        }
        else 
        {
            h2->next = merge(h1, h2->next);
            return h2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode* ans = nullptr;
        int k = lists.size();
        for(int i=0;i<k;i++)    ans = merge(lists[i],ans);
        return ans;    
    }
};