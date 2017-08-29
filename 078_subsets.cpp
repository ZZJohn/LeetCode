vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> res;
	vector<int> tmp;
	int n = nums.size();
	res.push_back(tmp);
	if(n==0) return res;
	for(int count=1; count<=n; count++)
	{
		DFS(nums, count, 0, tmp, res);
	}
	return res;
}

void DFS(vector<int> nums, int count, int pos, vector<int> tmp, vector<vector<int>>& res)
{
	if(tmp.size() == count)
	{
		res.push_back(tmp);
		return;
	}
	for(int i=pos; i<=nums.size()-1; i++)
	{
		tmp.push_back(nums[i]);
		DFS(nums, count, i+1, tmp, res);
		tmp.pop_back();
	}
	return;
}