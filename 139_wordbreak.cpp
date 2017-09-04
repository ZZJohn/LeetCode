bool wordBreak(string s, vector<string>& wordDict)
{
	int n = s.size();
	bool *res = new bool[n];
	for(int i=0; i<=n-1; i++)
	{
		res[i] = false;
		if(isExist(s, 0, i, wordDict))
		{
			res[i] = true;
			continue;
		}
		for(int j=i-1; j>=0; j--)
		{
			if(res[j] && isExist(s, j+1, i, wordDict))
			{
				res[i] = true;
				break;
			}
		}
	}
	return res[n-1];
}

bool isExist(string s, int start, int end, vector<string>& wordDict)
{
	vector<string>::iterator it = find(wordDict.begin(), wordDict.end(), s.substr(start, end-start+1));
	if(it == wordDict.end()) return false;
	else return true;
}