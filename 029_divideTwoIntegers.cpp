int divide(int dividend, int divisor)
{
	int flag = 1;
	if(dividend < 0)
		flag = -flag;
	if(divisor < 0)
		flag = -flag;
	if(divisor == 0)
		return INT_MAX;
	long long num1 = abs((long long) dividend);
	long long num2 = abs((long long) divisor);
	if(num1 < num2)
		return 0;
	long long res = 0;
	while(num1 >= num2)
	{
		int tmp = 0;
		long long tmp2 = num2;
		while(num1 >= tmp2)
		{
			tmp2 = tmp2 << 1;
			tmp++;
		}
		res += ((long long)1 << (tmp-1));
		num1 = num1 - (tmp2>>1);
	}
	if(res > INT_MAX)
		return (flag>0)?INT_MAX : INT_MIN; 
	return flag*res;
}