class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        struct ListNode *temp;
        if(!head->next) return NULL;
        temp=head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        count=count/2;
        temp=head;
        count--;
        while(count>0)
        {
            count--;
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};