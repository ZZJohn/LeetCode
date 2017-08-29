void helper(vector<int>& candidates, int target, int pos, int curr, vector<int>& path, vector<vector<int>>& res)
{
	if(curr == target)
	{
		res.push_back(path);
		return;
	}
	if(curr > target)
		return;
		for(int i=pos; i<candidates.size(); i++)
	{
		path.push_back(candidates[i]);
		helper(candidates, target, i, curr+candidates[i], path, res);
		path.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int>> res;
	vector<int> path;
	sort(candidates.begin(), candidates.end());
	helper(candidates, target, 0, 0, path, res);
	return res;
}