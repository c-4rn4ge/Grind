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
    ListNode *solve(ListNode *head, int x)
    {
        ListNode *s = nullptr, *l = nullptr, *fs = nullptr, *fl = nullptr;
        int f = 0, f1 = 0;
        while (head)
        {
            if (head->val < x)
            {
                if (!f)
                {
                    s = head;
                    fs = s;
                    f++;
                }
                else
                {
                    s->next = head, s = head;
                }
                head = head->next;
                s->next = nullptr;
            }
            else
            {
                if (!f1)
                {
                    l = head;
                    fl = l;
                    f1++;
                }
                else
                {
                    l->next = head, l = head;
                }
                head = head -> next;
                l -> next = nullptr;
            }
        }
        if (fs)
            s->next = fl;
        else return fl;
        return fs;
    }
    ListNode *partition(ListNode *head, int x)
    {
        if (!head || !head->next)
            return head;
        return solve(head, x);
    }
};