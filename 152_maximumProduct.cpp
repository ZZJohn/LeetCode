int maxProduct(vector<int>& nums)
{
	int n = nums.size();
	int max2 = nums[0];
	int min2 = nums[0];
	int res = nums[0];
	for(int i=1; i<=n-1; i++)
	{
		int a = max2*nums[i];
		int b = min2*nums[i];
		max2 = max(max(a, b), nums[i]);
		min2 = min(min(a, b), nums[i]);
		res = max(res, max2);
	}
	return res;
}