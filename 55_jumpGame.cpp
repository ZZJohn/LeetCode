bool canJump(vector<int>& nums)
{
	int n = nums.size();
	if(n == 0) return false;
	int maxjump = -1;;
	for(int i=0; i<=n-1; i++)
	{
		if(nums[i] > maxjump)
			maxjump = nums[i];
		if(i+maxjump >= n-1)
			return true;
		if(maxjump == 0)
			return false;
		maxjump--;
	}
	return false;
}