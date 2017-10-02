public int climbStairs(int n)
{
	if(n==0 || n==1 || n==2) return n;
	int[] res = new int[n];
	res[0] = 1;
	res[1] = 2;
	for(int i=2; i<=n-1; i++)
	{
		res[i] = res[i-1]+res[i-2];
	}
	return res[n-1];
}