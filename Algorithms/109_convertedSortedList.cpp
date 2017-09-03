TreeNode* sortedListToBST(ListNode* head)
{
	return helper(head, NULL);
}

TreeNode* helper(ListNode* start, ListNode* end)
{
	if(start == end)
		return NULL;
	ListNode* fast = start;
	ListNode* slow = start;
	while(fast!=end && fast->next!=end)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	TreeNode* root = new TreeNode(slow->val);
	root->left = helper(start, slow);
	root->right = helper(slow->next, end);
	return root;
}
