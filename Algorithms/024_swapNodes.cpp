ListNode* swapPairs(ListNode* head)
{
	if(head == NULL) return NULL;
	if(head->next == NULL) return head;
	ListNode *tmp;
	tmp = head->next;
	head->next = swapPairs(tmp->next);
	tmp->next = head;
	return tmp;
}