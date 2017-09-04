vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	int n = nums.size();
	vector<vector<int>> res;
	vector<int> empty;
	res.push_back(empty);
	if(n==0) return res;
	sort(nums.begin(), nums.end());
	vector<vector<int>> layer;
	int len;
	for(int i=0; i<=n-1; i++)
	{
		if(i>=1 && nums[i] == nums[i-1])
		{
			for(int j=0; j<layer.size(); j++)
			{
				res.push_back(layer[j]);
				res.back().push_back(nums[i]);
				layer[j].push_back(nums[i]);
			}
		}
		else
		{
			layer.clear();
			len = res.size();
			for(int j=0; j<=len-1; j++)
			{
				res.push_back(res[j]);
				layer.push_back(res[j]);
				res.back().push_back(nums[i]);
				layer.back().push_back(nums[i]);
			}
		}
	}
	return res;
}