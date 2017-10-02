public int longestConsecutive(int[] nums)
{
	Map<Integer, Integer> map = new HashMap<>();
	int n = nums.length;
	if(n==0 || n==1)
		return n;
	int res = 0;
	for(int i=0; i<=n-1; i++)
	{
		if(map.containsKey(nums[i]) == false)
		{
			int left = map.containsKey(nums[i]-1) ? map.get(nums[i]-1):0;
			int right = map.containsKey(nums[i]+1) ? map.get(nums[i]+1):0;
			int sum = left+right+1;
			res = Math.max(sum, res);
			map.put(nums[i], sum);
			map.put(nums[i]-left, sum);
			map.put(nums[i]+right, sum);
		}
		else
			continue;
	}
	return res;
}