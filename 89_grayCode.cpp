vector<int> grayCode(int n)
{
	vector<int> res(1, 0);
	for(int i=0; i<n; i++)
	{
		int length = res.size();
		for(int j=length-1; j>=0; j--)
		{
			int curr = res[j];
			curr += 1<<i;
			res.push_back(curr);
		}
	}
	return res;
}