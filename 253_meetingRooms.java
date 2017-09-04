public int minMeetingRooms(Interval[] intervals)
{
	if(intervals.length <= 1)
		return intervals.length;
	Arrays.sort(intervals, new Comparator<Interval>(){
		public int compare(Interval a, Interval b)
		{
			return a.start-b.start;
		}
	});
	PriorityQueue<Interval> heap = new PriorityQueue<>
	(intervals.length, new Comparator<Interval>(){
		public int compare(Interval a, Interval b)
		{
			return a.end-b.end;
		}
	});
	heap.offer(intervals[0]);
	for(int i=1; i<=intervals.length-1; i++)
	{
		Interval curr = heap.poll();
		if(intervals[i].start >= curr.end)
			curr.end = intervals[i].end;
		else
			heap.offer(intervals[i]);
		heap.offer(curr);
	}
	return heap.size();
}