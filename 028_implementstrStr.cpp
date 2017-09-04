int strStr(string haystack, string needle)
{
	if(haystack.size() < needle.size())
		return -1;
	if(needle.size() == 0)
		return 0;
	vector<int> next = getNext(needle);
	int i = 0;
	int j = 0;
	while(i < haystack.size())
	{
		if(j==-1 || haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		else j = next[j];
		if(j == needle.size()) return i-j;
	}
	return -1;
}

vector<int> getNext(string s)
{
	int n = s.size();
	vector<int> next(n, 0);
	next[0] = -1;
	int i = 0;
	int j = -1;
	while(i < n-1)
	{
		if(j == -1 || s[i] == s[j])
		{
			j++;
			i++;
			next[i] = j;
		}
		else j = next[j];
	}
	return next;
}