vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	vector<vector<string>> res;
	int n = strs.size();
	if(n==0) 
		return res;
	sort(strs.begin(), strs.end());
	map<string, vector<string>> mv;
	for(int i=0; i<n; i++)
	{
		string tmp = strs[i];
		sort(tmp.begin(), tmp.end());
		mv[tmp].push_back(strs[i]);
	}
	for(map<string, vector<string>>::iterator it=mv.begin(); it!=mv.end();it++)
		res.push_back(it->second);
	return res;
}