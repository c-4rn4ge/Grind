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
    ListNode* merge(ListNode* l1, ListNode* l2) 
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* head = new ListNode(-1), *p = head;
        while(l1 != NULL && l2 != NULL) 
        {
            if(l1->val < l2->val) 
            {
                p->next = l1;
                l1 = l1->next;
            }
            else 
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1 != NULL) p->next = l1;
        if(l2 != NULL) p->next = l2;
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode* ans = nullptr;
        int k = lists.size();
        for(int i=0;i<k;i++)    ans = merge(lists[i],ans);
        return ans;    
    }
};