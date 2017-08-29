ListNode* rotateRight(ListNode* head, int k)
{
	int count = 1;
	if(k==0 || head==NULL) return head;
	ListNode *l1, *l2, *lc;
	l1 = l2 = lc = head;
	while(lc->next != NULL)
	{
		lc = lc->next;
		count++;
	}
	k = k%count;
	while(k>0 && l2)
	{
		l2 = l2->next;
		k--;
	}
	if(l2==NULL) return head;
	while(l2->next != NULL)
	{
		l2 = l2->next;
		l1 = l1->next;
	}
	l2->next = head;
	ListNode *tmp = l1->next;
	l1->next = NULL;
	return tmp;
}