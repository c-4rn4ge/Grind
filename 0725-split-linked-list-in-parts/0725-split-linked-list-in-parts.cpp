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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int n = 0;
        ListNode *temp = head;
        vector<ListNode *> ans;
        while (temp)
        {
            n++;
            temp = temp->next;
        }
        int bSize = n / k, rem = n % k;
        temp = head;
        for (int i = 0; i < k; i++)
        {
            int pSize = bSize + (rem > 0);
            ListNode *h = NULL, *t = NULL;
            for (int j = 0; j < pSize; j++)
            {
                if (!h) h = t = temp;
                else
                {
                    t->next = temp;
                    t = t->next;
                }
                if (temp)   temp = temp->next;
            }
            if (t)  t->next = NULL;
            ans.push_back(h);
            rem = max(rem - 1, 0);
        }
        return ans;
    }
};