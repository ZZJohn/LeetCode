string countAndSay(int n)
{
	if(n==1)
		return "1";
	string prev = countAndSay(n-1);
	int count = 0;
	int before = prev[0] - '0';
	string res;
	for(int i=0; i<prev.size(); i++)
	{
		if(prev[i]-'0' == before)
		{
			count++;
		}
		else{
			before = prev[i] - '0';
			res += '0' + count;
			res +=prev[i-1];
			count = 1;
		}
		if(i == prev.size()-1)
		{
			res += '0' + count;
			res +=prev[i];
		}
	}
	return res;
}