ListNode* deleteDuplicates(ListNode* head)
{
	if(head==NULL || head->next==NULL) return head;
	ListNode *p = head->next;
	if(p->val != head->val)
	{
		head->next = deleteDuplicates(p);
		return head;
	}
	else
	{
		while(p && p->val == head->val) p = p->next;
		return deleteDuplicates(p);
	}
}