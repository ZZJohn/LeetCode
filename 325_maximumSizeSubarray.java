public int maxSubArrayLen(int[] nums, int k)
{
	int sum = 0;
	int max = 0;
	int n = nums.length;
	Map<Integer, Integer> mapping = new HashMap<Integer, Integer>();
	for(int i=0; i<=n-1; i++)
	{
		sum += nums[i];
		if(sum == k) max = i+1;
		else if(mapping.containsKey(sum-k))
			max = Math.max(max, i-mapping.get(sum-k));
		if(!mapping.containsKey(sum)) mapping.put(sum, i);
	}
	return max;
}