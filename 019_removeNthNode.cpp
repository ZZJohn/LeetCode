ListNode* removeNthFromEnd(ListNode* head, int n)
{
	ListNode *l1, *l2;
	l1 = l2 = head;
	while(n>0)
	{
		l2 = l2->next;
		n--;
	}
	if(l2 == NULL) return head->next;
	while(l2->next != NULL)
	{
		l2 = l2->next;
		l1 = l1->next;
	}
	l1->next = l1->next->next;
	return head;
}