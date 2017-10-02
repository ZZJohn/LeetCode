public ListNode reverseKGroup(ListNode head, int k) 
{
	ListNode dummy = new ListNode(0);
	dummy.next = head;
	ListNode prev = dummy;
	ListNode tail = dummy;
	int count;
	while(true)
	{
		count = k;
		while(count>0 && tail!=null)
		{
			count--;
			tail = tail.next;
		}
		if(tail == null)
			break;
		head = prev.next;
		while(prev.next != tail)
		{
			ListNode tmp = prev.next;
			prev.next = tmp.next;
			tmp.next = tail.next;
			tail.next = tmp;
		}
		tail = head;
		prev = head;
	}
	return dummy.next;
}