public List<String> removeInvalidParentheses(String s)
{
	Set<String> res = new HashSet<>();
	int n = s.length();
	int maxL = 0, maxR = 0;
	StringBuilder tmp = new StringBuilder();
	int open = 0;
	for(int i=0; i<=n-1; i++)
	{
		if(s.charAt(i) == '(')
			maxL++;
		if(s.charAt(i) == ')')
		{
			if(maxL>0) maxL--;
			else maxR++;
		}
	}
	helper(res, s, maxL, maxR, tmp, open, 0);
	return new ArrayList<String>(res);

}

void helper(Set<String> res, String s, int maxL, int maxR, StringBuilder tmp, int open, int i)
{
	if(open==0 && maxL==0 && maxR==0 && i==s.length())
	{
		res.add(tmp.toString());
		return;
	}
	if(maxL<0 || maxR<0 || i>=s.length() || open<0)
		return;
	int len = tmp.length();
	if(s.charAt(i) == '(')
	{
		helper(res, s, maxL-1, maxR, tmp, open, i+1);
		helper(res, s, maxL, maxR, tmp.append('('), open+1, i+1);
	}
	else if(s.charAt(i) == ')')
	{
		helper(res, s, maxL, maxR-1, tmp, open, i+1);
		helper(res, s, maxL, maxR, tmp.append(')'), open-1, i+1);
	}
	else
		helper(res, s, maxL, maxR, tmp.append(s.charAt(i)), open, i+1);
	tmp.setLength(len);
}