public int divide(int dividend, int divisor)
{
	if(divisor == 0 || (dividend == Integer.MIN_VALUE && divisor == -1))
		return Integer.MAX_VALUE;
	long dd = Math.abs((long)dividend);
	long ds = Math.abs((long)divisor);
	int sign = (dividend < 0) ^ (divisor < 0) ? -1:1;
	int res = 0;
	while(dd >= ds)
	{
		int multiple = 1;
		long tmp = ds;
		while(dd >= (tmp<<1))
		{
			tmp <<= 1;
			multiple <<= 1;
		}
		dd -= tmp;
		res += multiple;
	}
	return sign*res;
}