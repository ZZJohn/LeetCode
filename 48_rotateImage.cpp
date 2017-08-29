void rotate(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	if(m==0 || m==1) return;
	for(int i=1; i<m; i++)
		for(int j=0; j<i; j++)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	for(int i=0; i<m; i++)
		for(int j=0; j<m/2; j++)
		{
			swap(matrix[i][j], matrix[i][m-1-j]);
		}
}