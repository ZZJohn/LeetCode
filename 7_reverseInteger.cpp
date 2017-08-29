int reverse(int x) 
{
	long long result = 0;
	while(x)
	{
		int t = x/10;
		result = result*10 + (x - t*10);
		x = x/10;
	}
	if(result < INT_MIN || result > INT_MAX) return 0;
	return result;
}