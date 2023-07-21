class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {   
        if(!head||!head->next) return head;
        struct ListNode *THead = reverseList(head->next);
        head -> next -> next = head;
        head -> next = NULL;
        return THead; 
    }
};