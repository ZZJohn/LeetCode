int maxProfit(vector<int>& prices)
{
	int n = prices.size();
	if(n==0 || n==1) return 0;
	int res = 0;
	int tmp = 0;
	int min = prices[0];
	for(int i=1; i<=n-1; i++)
	{
		if(prices[i]<min)
			min = prices[i];
		else
		{
			tmp = prices[i] - min;
			if(tmp > res)
				res = tmp;
		}
	}
	return res;
}