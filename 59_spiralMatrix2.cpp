vector<vector<int>> generateMatrix(int n)
{
	vector<vector<int>> res(n, vector<int>(n, 0));
	int k=1;
	for(int i=0; i<=(n-1)/2; i++)
	{
		for(int j=i; j<=n-1-i; j++)
		{
			res[i][j] = k;
			k++;
		}
		for(int j=i+1; j<=n-1-i; j++)
		{
			res[j][n-1-i] = k;
			k++;
		}
		for(int j=n-2-i; j>=i; j--)
		{
			res[n-1-i][j] = k;
			k++;
		}
		for(int j=n-2-i; j>=i+1; j--)
		{
			res[j][i] = k;
			k++;
		}
	}
	return res;
}