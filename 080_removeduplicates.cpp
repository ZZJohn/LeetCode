int removeDuplicates(vector<int>& nums)
{
	int n = nums.size();
	if(n == 0 || n == 1) return n;
	int pre = nums[0];
	int count = 1;
	int sum = 1;
	for(int i=1; i<=n-1; i++)
	{
		if(nums[i] == pre)
		{
			count++;
			if(count <= 2)
			{
				sum++;
				nums[sum-1] = nums[i];
			}
		}
		else
		{
			count = 1;
			pre = nums[i];
			sum++;
			nums[sum-1] = nums[i];
		}
	}
	return sum;
}