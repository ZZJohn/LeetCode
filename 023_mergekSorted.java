public ListNode mergeKLists(ListNode[] lists)
{
	if(lists.length == 0)
		return null;
	PriorityQueue<ListNode> queue = new PriorityQueue<>(lists.length, new Comparator<ListNode>()
	{
		public int compare(ListNode a, ListNode b)
		{
			return a.val - b.val;
		}
	});
	ListNode dummyhead = new ListNode(0);
	ListNode tail = dummyhead;
	for(int i=0; i<=lists.length-1; i++)
		if(lists[i] != null)
			queue.offer(lists[i]);
	while(!queue.isEmpty())
	{
		ListNode node = queue.poll();
		tail.next = node;
		tail = tail.next;
		if(node.next!=null)
			queue.offer(node.next);
	}
	return dummyhead.next;
}