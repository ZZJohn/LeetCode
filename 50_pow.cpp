double myPow(double x, int n)
{
	if(n==0 || x==1.0)
		return 1.0;
	if(n<0)
	{
		if(n==INT_MIN) return 1.0/(x*myPow(x, INT_MAX));
		return 1.0/myPow(x, -n);
	}
	double res = 1.0;
	while(n>0)
	{
		if(n&1)
			res *= x;
		x *= x;
		n = n >> 1;
	}
	return res;
}