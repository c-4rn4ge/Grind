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
class Solution 
{
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head) return head;
        int n=1;
        ListNode *h, *t;
        h = t = head;
        while(t->next)  t = t->next,n++;
        t->next = head; 
        k = k % n;
        if(k)   for(auto i=0; i<n-k; i++) t = t->next;
        h = t->next; 
        t->next = NULL;
        return h;
    }
};