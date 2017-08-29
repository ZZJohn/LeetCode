int threeSumClosest(vector<int>& nums, int target)
{
	int n = nums.size();
	int closeSum = nums[0] + nums[1] + nums[2];
	sort(nums.begin(), nums.end());
	for (int i=0; i<n-2; i++)
	{
		int head = i+1, tail = n-1;
		while(head < tail)
		{
			int sum = nums[i] + nums[head] + nums[tail];
			if(sum == target) return target;
			else if(sum < target) head++;
			else tail--;
			if(abs(sum-target) < abs(closeSum-target))
				closeSum = sum;
		}
	}
	return closeSum;
}