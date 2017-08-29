int climbStairs(int n)
{
	vector<int> res(n, 0);
	res[0] = 1;
	if(n==1) return res[n-1];
	res[1] = 2;
	if(n==2) return res[n-1];
	for(int i=2; i<n; i++)
		res[i] = res[i-1] + res[i-2];
	return res[n-1];
}