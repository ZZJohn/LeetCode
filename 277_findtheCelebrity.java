public int findCelebrity(int n)
{
	int candidate = 0;
	for(int i=1; i<=n-1; i++)
		if(!knows(i, candidate))
			candidate = i;
	for(int j=0; j<=n-1; j++)
	{
		if(j==candidate)
			continue;
		if(knows(candidate, j) || !knows(j, candidate))
			return -1;
	}
	return candidate;
}