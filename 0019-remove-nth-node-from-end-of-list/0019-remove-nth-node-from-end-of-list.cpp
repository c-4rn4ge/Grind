class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *fast=head,*slow = head;
        while(n--) fast = fast->next;
        if(!fast) return head->next;
        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};