string intToRoman(int num)
{
	string s;
	int n[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	string r[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int i=0;
	while(num > 0)
	{
		int k = num / n[i];
		num = num % n[i];
		for(int j=0; j<k; j++)
			s += r[i];
		i++;
	}
	return s;
}