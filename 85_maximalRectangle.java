public int maximalRectangle(char[][] matrix) 
{
    int m = matrix.length;
    if(m==0)
        return 0;
    int n = matrix[0].length;
    if(n==0)
        return 0;
    int[] left = new int[n];
    int[] right = new int[n];
    int[] height = new int[n];
    int res = 0;
    Arrays.fill(right, n);
    for(int i=0; i<=m-1; i++)
    {
        int cur_left = 0;
        int cur_right = n;
        for(int j=0; j<=n-1; j++)
        {
            if(matrix[i][j] == '1')
                height[j]++;
            else
                height[j] = 0;
        }
        for(int j=0; j<=n-1; j++)
        {
            if(matrix[i][j] == '1')
                left[j] = Math.max(left[j], cur_left);
            else
            {
                left[j] = 0;
                cur_left = j+1;
            }
        }
        for(int j=n-1; j>=0; j--)
        {
            if(matrix[i][j] == '1')
                right[j] = Math.min(right[j], cur_right);
            else
            {
                right[j] = n;
                cur_right = j;
            }
        }
        for(int j=0; j<=n-1; j++)
            res = Math.max(res, (right[j]-left[j])*height[j]);
    }
    return res;
}