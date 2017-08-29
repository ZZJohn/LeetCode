ListNode* deleteDuplicates(ListNode* head)
{
	ListNode* tmp = head;
	if(head == NULL) return head;
	int map = tmp->val;
	while(tmp->next != NULL)
	{
		if(tmp->next->val != map)
		{
			tmp = tmp->next;
			map = tmp->val;
		}
		else
			tmp->next = tmp->next->next;
	}
	return head;
}