public void moveZeros(int[] nums)
{
	int n = nums.length;
	if(n<=1) return;
	int insertPos = 0;
	for(int num: nums)
		if(num != 0) nums[insertPos++] = num;
	while(insertPos <= n-1)
		nums[insertPos++] = 0;
}