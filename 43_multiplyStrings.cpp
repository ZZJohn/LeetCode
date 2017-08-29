string multiply(string num1, string num2)
{
	vector<int> res(num1.size()+num2.size(), 0);
	for(int i=0; i<num1.size(); i++)
		for(int j=0; j<num2.size(); j++)
			res[i+j] += (num1[num1.size()-i-1]-'0') * (num2[num2.size()-j-1]-'0');
	int tmp = 0;
	for(int i=0; i<res.size(); i++)
	{
		res[i] += tmp;
		tmp = res[i] / 10;
		res[i] %= 10;
	}
	string s="";
	int n = res.size();
	int i = n-1;
	while(res[i] == 0)
		i--;
	if(i<0)
		return "0";
	while(i>=0)
	{
		s += res[i] + '0';
		i--;
	}
	return s;
}