vector<int> plusOne(vector<int>& digits)
{
	int n = digits.size();
	digits[n-1] ++;
	for(int i=0; i<n-1; i++)
	{
		if(digits[n-i-1] >= 10)
		{
			digits[n-i-1] = 0;
			digits[n-i-2] ++;
		}
	}
	if(digits[0] == 10)
	{
		digits[0] = 0;
		digits.insert(digits.begin(), 1);
	}
	return digits;
}