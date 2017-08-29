vector<vector<int>> permuteUnique(vector<int>& nums)
{
	vector<vector<int>> res;
	if(nums.size() == 0) return res;
	DFS(nums, res, 0);
	return res;
}

void DFS(vector<int> nums, vector<vector<int>>& res, int pos)
{
	if(pos == nums.size()-1)
	{
		res.push_back(nums);
		return;
	}
	sort(nums.begin()+pos, nums.end());
	for(int i=pos; i<=nums.size()-1; i++)
	{
		if(i!=pos && nums[i] == nums[i-1]) continue;
		swap(nums[i], nums[pos]);
		DFS(nums, res, pos+1);
		swap(nums[pos], nums[i]);
	}
	return;
}