public int jump(int[] nums) 
{
	int n = nums.length;
	if(n<=1)
		return 0;
	int index = 0;
	int res = 0;
	int currMax = 0;
	int nextMax = 0;
	while(true)
	{
		res++;
		while(index<=currMax)
		{
			if(nums[index]+index>=nextMax)
				nextMax = nums[index]+index;
			if(nextMax>=n-1)
				return res;
			index++;
		}
		currMax = nextMax;
	}
}