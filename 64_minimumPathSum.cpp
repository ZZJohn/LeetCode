int minPathSum(vector<vector<int>>& grid)
{
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> res = grid;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==0 && j==0) continue;
			if(i==0)
			{
				res[i][j] += res[i][j-1];
				continue;
			}
			if(j==0) 
			{
				res[i][j] += res[i-1][j];
				continue;
			}
			res[i][j] += min(res[i-1][j], res[i][j-1]);
		}
	}
	return res[m-1][n-1];
}