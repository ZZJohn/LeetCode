vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> res;
	int m = matrix.size();
	if(m == 0) return res;
	int n = matrix[0].size();
	int k = min(m, n);
	if(k%2 == 0) k--;
	k = k/2;
	for(int i=0; i<=k; i++)
	{
		for(int j=i; j<=n-1-i; j++)
			res.push_back(matrix[i][j]);
		if(m-1-i <= i)
			break;
		for(int j=i+1; j<=m-1-i; j++)
			res.push_back(matrix[j][n-1-i]);
		if(n-1-i <= i)
			break;
		for(int j=n-2-i; j>=i; j--)
			res.push_back(matrix[m-1-i][j]);
		for(int j=m-2-i; j>=i+1; j--)
			res.push_back(matrix[j][i]);
	}
	return res;
}