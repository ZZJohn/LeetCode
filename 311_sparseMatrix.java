public int[][] multiply(int[][] A, int[][] B)
{
	int m = A.length;
	int n = A[0].length;
	int l = B[0].length;
	int[][] res = new int[m][l];
	for(int i=0; i<=m-1; i++)
		for(int j=0; j<=n-1; j++)
		{
			if(A[i][j] != 0)
				for(int k=0; k<=l-1; k++)
					if(B[j][k] != 0)
						res[i][k] += A[i][j] * B[j][k];
		}
	return res;
}