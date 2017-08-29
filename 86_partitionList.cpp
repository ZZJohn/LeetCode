ListNode* partition(ListNode* head, int x)
{
	if(head == NULL || head->next == NULL) return head;
	ListNode* dummy_head = new ListNode(INT_MIN);
	dummy_head ->next = head;
	ListNode* p = dummy_head;
	while(p->val < x && p->next != NULL)
	{
		if(p->next->val < x)
			p = p->next;
		else
			break;
	}
	ListNode* q = p->next;
	ListNode* q_pre = p;
	while(q!=NULL)
	{
		while(q && q->val >= x)
		{
			q_pre = q_pre->next;
			q = q->next;
		}
		if(!q) break;
		ListNode* tmp = q->next;
		q->next = p->next;
		p->next = q;
		q_pre->next = tmp;
		p = p->next;
		q = tmp;
	}
	return dummy_head->next;
}