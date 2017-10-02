public int firstBadVersion(int n)
{
	int l=1, r=n;
	while(l<r)
	{
		int m = (l+r)/2;
		if(isBadVersion(m))
			r=m;
		else
			l=m+1;
	}
	return l;
}