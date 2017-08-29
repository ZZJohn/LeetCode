int binarySearchLow(vector<int>& nums, int target, int begin, int end)
{
	if(begin > end) return begin;
	int mid = begin + (end-begin)/2;
	if(nums[mid] < target) return binarySearchLow(nums, target, mid+1, end);
	else return binarySearchLow(nums, target, begin, mid-1);
}

int binarySearchHigh(vector<int>& nums, int target, int begin, int end)
{
	if(begin > end) return end;
	int mid = begin + (end-begin)/2;
	if(nums[mid] > target) return binarySearchHigh(nums, target, begin, mid-1);
	else return binarySearchHigh(nums, target, mid+1, end);
}

vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> res(2, -1);
	int n = nums.size();
	if(n==0) return res;
	int low = binarySearchLow(nums, target, 0, n-1);
	int high = binarySearchHigh(nums, target, 0, n-1);
	if(low <= high)
	{
		res[0] = low;
		res[1] = high;
		return res;
	}
	return res;
}