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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if (!head || left == right) return head;    
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;
        int i;
        for (i = 0; i < left - 1; i++)  p = p->next;
        ListNode* c = p->next;
        while(i < right - 1) 
        {
            ListNode* f = c->next;
            c->next = f->next;
            f->next = p->next;
            p->next = f;
            i++;
        }
        return dummy.next;
    }
};