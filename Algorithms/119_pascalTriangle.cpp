vector<int> getRow(int rowIndex)
{
	vector<int> last(1, 1);
	if(rowIndex == 0)
		return last;
	vector<int> path;
	for(int i=1; i<=rowIndex; i++)
	{
		last.push_back(0);
		path = last;
		for(int j=1; j<=last.size()-1; j++)
			path[j] = last[j] + last[j-1];
		last = path;
	}
	return path;
}