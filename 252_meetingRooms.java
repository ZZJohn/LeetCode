public boolean canAttendMeetings(Interval[] intervals)
{
	Arrays.sort(intervals, new Comparator<Interval>(){
		public int compare(Interval a, Interval b){return a.start-b.start;}
	});
	int n = intervals.length;
	for(int i=0; i<=n-2; i++)
		if(intervals[i].end > intervals[i+1].start)
			return false;
	return true;
}