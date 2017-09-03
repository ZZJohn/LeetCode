public RandomListNode copyRandomList(RandomListNode head)
{
	RandomListNode curr = head;
	RandomListNode next;
	while(curr != null)
	{
		RandomListNode copy = new RandomListNode(curr.label);
		next = curr.next;
		curr.next = copy;
		copy.next = next;
		curr = next;
	}
	curr = head;
	while(curr != null)
	{
		if(curr.random != null)
			curr.next.random = curr.random.next;
		curr = curr.next.next;
	}
	curr = head;
	RandomListNode phead = new RandomListNode(0);
	RandomListNode copy = phead, currcopy = phead;
	while(curr != null)
	{
		copy = curr.next;
		currcopy.next = copy;
		currcopy = currcopy.next;
		curr.next = curr.next.next;
		curr = curr.next;
	}
	return phead.next;
}