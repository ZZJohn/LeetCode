void nextPermutation(vector<int>& nums)
{
	int n = nums.size();
	if(n==1) return;
	int i = n-1;
	while(nums[i] <= nums[i-1])
	{
		if(i==1)
		{
			sort(nums.begin(), nums.end());
			return;
		}
		i--;
	}
	i--;
	for(int j = i+1; j<n; j++)
	{
		if(nums[j] <= nums[i])
		{
			int temp = nums[i];
			nums[i] = nums[j-1];
			nums[j-1] = temp;
			sort(nums.begin()+i+1, nums.end());
			return;
		}
		if(j==n-1)
		{
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			sort(nums.begin()+i+1, nums.end());
			return;
		}
	}
}