struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *l3=malloc(sizeof(struct ListNode));
    l3 ->val = 0;l3->next = NULL;
    struct ListNode *p=l3;
    int c = 0;
    while(l1!=NULL||l2!=NULL||c)
    {
            int sum = 0;
			if (l1 != NULL)
			{
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				sum += l2->val;
				l2 = l2->next;
			}
			sum += c;
			c = sum / 10; 
            struct ListNode *t = malloc(sizeof(struct ListNode));
            t -> val = sum%10;t-> next = NULL;
            p ->next = t;
            p = p->next;
    }
    return l3->next;
}
