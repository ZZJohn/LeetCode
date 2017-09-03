ListNode* reverseBetween(ListNode* head, int m, int n)
{
	if(head == NULL || m==n)
		return head;
	ListNode* dummy_head = new ListNode(-1);
	dummy_head->next = head;
	m++;
	n++;
	ListNode* p_m = dummy_head;
	ListNode* p_m_previous;
	for(int i=1; i<=m-1; i++)
	{
		p_m_previous = p_m;
		p_m = p_m->next;
	}
	int count = n-m;
	ListNode* p = p_m;
	ListNode* q = p->next;
	ListNode* r = q->next;
	while(count>0)
	{
		q->next = p;
		p = q;
		q = r;
		if(r!= NULL) r=r->next;
		count--;
	}
	p_m_previous->next = p;
	p_m->next = q;
	head = dummy_head->next;
	return head;
}