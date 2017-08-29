int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<vector<int>> res = obstacleGrid;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==0 && j==0)
			{
				if(res[i][j] == 1) return 0;
				res[i][j] = 1;
				continue;
			}
			if(res[i][j] == 1) 
			{
				res[i][j] = 0;
				continue;
			}
			else 
			{
				if(i>=1) res[i][j] += res[i-1][j];
				if(j>=1) res[i][j] += res[i][j-1];
			}
		}
	}
	return res[m-1][n-1];
}