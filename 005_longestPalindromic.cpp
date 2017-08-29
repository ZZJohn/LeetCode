string longestPalindrome(string s) 
{
	if(s.empty()) return "";
	if(s.size() == 1) return s;
	int n = s.length();
	int longestbegin = 0;
	int maxlen = 1;
	int len = 1;
	bool table[1000][1000] = {0};
	for (int i = 0; i < n; i++)
		table[i][i] = 1;
	for (int i = 0; i < n-1; i++)
	{
		if(s[i] == s[i+1]) 
		{
			table[i][i+1] = 1;
			longestbegin = i;
			maxlen = 2;
		}
	}
	for (len = 3; len <= n; len++)
		for( int i = 0; i <= n-len; i++) 
		{
			int j = i + len - 1;
			if((s[i] == s[j]) && table[i+1][j-1] == 1) 
			{
				table[i][j] = 1;
				longestbegin = i;
				maxlen = len;
			}
		}
	return(s.substr(longestbegin, maxlen));
}