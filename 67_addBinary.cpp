string addBinary(string a, string b)
{
	int na = a.size();
	int nb = b.size();
	if(na < nb) return addBinary(b, a);
	string zeros(na-nb, '0');
	b = zeros + b;
	int c = 0;
	for(int i=na-1; i>=0; i--)
	{
		int sum = a[i]-'0'+b[i]-'0'+c;
		c = 0;
		if(sum==1)
			a[i] = '1';
		if(sum==2)
		{
			a[i] = '0';
			c = 1;
		}
		if(sum==3)
		{
			a[i] = '1';
			c = 1;
		}
	}
	if(c==1)
		a = "1" + a;
	return a;
}