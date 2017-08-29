vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> res;
	int n = nums.size();
	if(n==0) return res;
	vector<int> visited;
	DFS(nums, visited, res);
	return res;
}

void DFS(vector<int> nums, vector<int>& visited, vector<vector<int>>& res)
{
	if(visited.size() == nums.size())
	{
		res.push_back(visited);
		return;
	}
	for(int i=0; i<=nums.size()-1; i++)
	{
		if(find(visited.begin(), visited.end(), nums[i]) == visited.end())
		{
			visited.push_back(nums[i]);
			DFS(nums, visited, res);
			visited.pop_back();
		}
	}
	return;
}