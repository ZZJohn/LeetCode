int singleNumber(vector<int>& nums)
{
	int n = nums.size();
	int res = 0;
	for(int i=0; i<=n-1; i++)
		res ^= nums[i];
	return res;
}