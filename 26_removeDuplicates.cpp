int removeDuplicates(vector<int>& nums)
{
	int n = nums.size();
	if(n==1 || n==0) return n;
	int l = 1;
	for(int i=1; i<n; i++)
	{
		if(nums[i] != nums[i-1])
		{
			nums[l] = nums[i];
			l++;
		}
	}
	return l;
}