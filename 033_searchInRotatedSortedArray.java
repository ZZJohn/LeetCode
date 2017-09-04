public int search(int[] nums, int target)
{
	int s = 0, t = nums.length-1;
	while(s <= t)
	{
		int m = (s+t)/2;
		if(nums[m] == target)
			return m;
		if(nums[m] <= nums[t])
		{
			if(target > nums[m] && target <=nums[t])
				s = m+1;
			else
				t = m-1;
		}
		else
		{
			if(target < nums[m] && target >= nums[s])
				t = m-1;
			else
				s = m+1;
		}
	}
	return -1;
}