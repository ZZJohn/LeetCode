vector<string> letterCombinations(string digits)
{
	vector<string> res;
	if(digits.size() == 0) return res;
	res.push_back("");
	vector<string> map(10, "");
	map[2] = "abc";
	map[3] = "def";
	map[4] = "ghi";
	map[5] = "jkl";
	map[6] = "mno";
	map[7] = "pqrs";
	map[8] = "tuv";
	map[9] = "wxyz";
	for(int i=0; i<digits.size(); i++)
	{
		int n = res.size();
		for(int j=0; j<n; j++)
		{
			string curr = res[0];
			res.erase(res.begin());
			for(int k=0; k<map[digits[i]-'0'].size(); k++)
			{
				res.push_back(curr + map[digits[i]-'0'][k]);
			}
		}
	}
	return res;
}