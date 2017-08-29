void DFS(int n, int k, int pos, vector<int> tmp, vector<vector<int>>& res)
{
	if(tmp.size() == k)
	{
		res.push_back(tmp);
		return;
	}
	for(int i=pos; i<=n-1; i++)
	{
		tmp.push_back(i+1);
		DFS(n, k, i+1, tmp, res);
		tmp.pop_back();
	}
	return;
}

vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> res;
	if(n==0 || k==0) return res;
	vector<int> tmp;
	DFS(n, k, 0, tmp, res);
	return res;
}