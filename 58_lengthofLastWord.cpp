int lengthOfLastWord(string s)
{
	int n = s.size();
	if(n==0) return 0;
	int i=n-1;
	int res = 0;
	while(s[i] == ' ')
		i--;
	while(i>=0)
	{
		if(s[i] == ' ')
			break;
		res++;
		i--;
	}
	return res;
}