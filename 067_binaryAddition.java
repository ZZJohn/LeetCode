public String addBinary(String a, String b)
{
	StringBuilder res = new StringBuilder();
	int i = a.length()-1, j = b.length()-1;
	int c = 0;
	while(i>=0 || j>=0 || c==1)
	{
		c += i>=0?a.charAt(i)-'0':0;
		c += j>=0?b.charAt(j)-'0':0;
		i--;
		j--;
		res.insert(0, String.valueOf(c%2));
		c = c/2;
	}
	return res.toString();
}