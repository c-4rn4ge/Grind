class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
         struct ListNode *temp;
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
        if(temp->next) temp->next=temp->next->next;
        else return head->next;
        return head;
    }
};