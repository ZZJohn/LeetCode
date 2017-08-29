static bool compare(Interval i1, Interval i2)
{
	if(i1.start < i2.start)
		return true;
	if(i1.start > i2.start)
		return false;
	return i1.end < i2.end;
}

vector<Interval> merge(vector<Interval>& intervals)
{
	int n = intervals.size();
	if(n==0 || n==1) return intervals;
	vector<Interval> res;
	sort(intervals.begin(), intervals.end(), compare);
	res.push_back(intervals[0]);
	int k=0;
	for(int i=1; i<=n-1; i++)
	{
		if(intervals[i].end <= res[k].end)
			continue;
		if(intervals[i].start<=res[k].end)
		{
			res[k].end = intervals[i].end;
		}
		else
		{
			res.push_back(intervals[i]);
			k++;
		}
	}
	return res;
}