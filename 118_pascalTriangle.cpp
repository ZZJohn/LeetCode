vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> res;
	if(numRows <= 0)
		return res;
	vector<int> last(1, 1);
	res.push_back(last);
	for(int i=1; i<numRows; i++)
	{
		last.push_back(0);
		vector<int> path = last;
		for(int j=1; j<=last.size()-1; j++)
			path[j] = last[j] + last[j-1];
		res.push_back(path);
		last = path;
	}
	return res;
}