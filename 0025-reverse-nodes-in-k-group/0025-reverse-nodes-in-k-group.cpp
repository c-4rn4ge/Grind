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
    ListNode* reverse(ListNode* f,ListNode**r,int k)
    {
            ListNode *prev , *curr,*next;
            prev = NULL;
            curr = f;
            next = curr->next;
            while(k--)
            {
                curr ->next = prev;
                prev = curr;
                curr = next;
                if(next !=NULL)next = next -> next;
            }
            *r = curr;
            f->next = curr;
            return prev;
    }
    int sizel(ListNode* head)
    {
        int n=0;
        while(head)
        {
            n++;
            head = head -> next;
        }
        return n;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(!head || !head ->next) return head;
        if(k==1) return head;
        int loops = sizel(head);
        loops /= k;
        loops --;
        ListNode *r;
        ListNode *ans = reverse(head,&r,k);
        ListNode *p = ans,*nh;
        while(loops--)
        {
            nh = r;
            head ->next = reverse(r,&r,k);
            head = nh;
        }
        head -> next = r;
        return ans;
    }
};