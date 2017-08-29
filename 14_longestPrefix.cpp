string longestCommonPrefix(vector<string>& strs)
{
	string res = "";
	int n = strs.size();
	if (n==0) return res;
	if (n==1) return strs[0];
	int minl = INT_MAX;
	for(int i=0; i<n; i++)
	{
		if(strs[i].size() < minl) minl = strs[i].size();
	}
	for(int j=0; j<minl; j++)
	{
		int flag = 0;
		for(int i=1; i<n; i++)
		{
			if(strs[i][j] != strs[i-1][j])
			{
				flag = 1;
				return res;
			}
		}
		if(flag == 0) res += strs[0][j];
	}
	return res;
}