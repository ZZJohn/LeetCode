void sortColors(vector<int>& nums)
{ 
	int low = 0;
	int mid = 0;
	int high = nums.size()-1;
	while(mid<=high)
	{
		if(nums[mid] == 0)
		{
			swap(nums, low, mid);
			low++;
			mid++;
		}
		else if(nums[mid] == 1)
		{
			mid++;
		}
		else
		{
			swap(nums, mid, high);
			high--;
		}
	}
}

void swap(vector<int>& nums, int a, int b)
{
	int tmp;
	tmp = nums[a];
	nums[a] = nums[b];
	nums[b] = tmp;
}