int numDecodings(string s)
{
	int n = s.size();
	if(n >= 1 && s[0] == '0') return 0;
	if(n==0 || n==1) return n;
	vector<int> res(n+1, 1);
	for(int i=1; i<=n-1; i++)
	{
		if(s[i] == '0')
		{
			if(s[i-1] == '1' || s[i-1] == '2')
				res[i+1] = res[i];
			else
				return 0;
		}
		else if(s[i-1]-'0'<=2 && s[i-1]!='0')
		{
			if(i+1<=n-1 && s[i+1] == '0')
				res[i+1] = res[i];
    		else if(s[i-1]-'0'==2 && s[i]-'0'>=7)
				res[i+1] = res[i];
			else res[i+1] = res[i-1] + res[i];
		}
		else
			res[i+1] = res[i];
	}
	return res[n];
}