bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	int m = matrix.size();
	if(m==0) return false;
	int n = matrix[0].size();
	if(n==0) return false;
	int low = 0;
	int high = m-1;
	while(low <= high)
	{
		int mid = low + (high-low)/2;
		if(matrix[mid][0] == target) return true;
		if(matrix[mid][0] > target)
			high = mid-1;
		else
			low = mid+1;
	}
	low--;
	if(low < 0) return false;
	int low2 = 0;
	int high2 = n-1;
	while(low2 <= high2)
	{
		int mid = low2 + (high2-low2)/2;
		if(matrix[low][mid] == target) return true;
		if(matrix[low][mid] > target)
			high2 = mid-1;
		else
			low2 = mid+1;
	}
	return false;
}