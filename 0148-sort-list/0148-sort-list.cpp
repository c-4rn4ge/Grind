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
private:
    ListNode* solve(ListNode *l1, ListNode *l2)
    {
        ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                curr -> next = l2;
                l2 = l2 -> next;
            }
            curr = curr ->next;
        }
        if(l1 != NULL)
        {
            curr -> next = l1;
            l1 = l1->next;
        }
        if(l2 != NULL)
        {
            curr -> next = l2;
            l2 = l2 ->next;
        }
        return ptr->next;
    }
public:
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head ->next) return head;    
        ListNode *t = NULL,*s = head,*f = head;
        while(f !=  NULL && f -> next != NULL)
        {
            t = s;
            s = s->next;         
            f = f ->next ->next;  
        }   
        t -> next = NULL;            
        ListNode* l1 = sortList(head);  
        ListNode* l2 = sortList(s);  
        return solve(l1, l2);       
    }
};