/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        if(!head ||!head->next ) return false;
        ListNode *s=head,*f=head->next;
        while(f&&f->next)
        {
            if(s==f) return true;
            s = s->next;
            f = f->next->next;
        } 
        return false;
    }
};