int romanToInt(string s)
{
	int n[] = {1000, 500, 100, 50, 10, 5, 1};
	char r[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
	int c[26];
	for(int i=0; i<7; i++)
		c[r[i]-'A'] = n[i];
	int l = s.size();
	int res = 0;
	for(int i=0; i<l; i++)
	{
		if((i<l-1) && c[s[i+1]-'A'] > c[s[i]-'A'])
		{
			res += c[s[i+1]-'A'] - c[s[i] - 'A'];
			i++;
		}
		else
			res += c[s[i] - 'A'];
	}
	return res;
}