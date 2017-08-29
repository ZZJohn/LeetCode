string getPermutation(int n, int k)
{
	if(n==1) return "1";
	vector<int> fac(n, 1);
	vector<char> digits(n, '1');
	string s = "";
	for(int i=1; i<n; i++)
		fac[i] = fac[i-1] * i;
	for(int i=0; i<n; i++)
		digits[i] += i;
	int i = n-1;
	k--;
	while(i >= 0)
	{
		int tmp = k / fac[i];
		s += digits[tmp];
		digits.erase(digits.begin()+tmp);
		k = k%fac[i];
		i--;
	}
	return s;
}