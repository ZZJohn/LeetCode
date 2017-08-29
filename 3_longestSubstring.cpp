#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
	int n = s.length();
	if(n == 0) return 0;
	string substring;
	int i = 0;
	int curr = 0;
	int flag = 0;
	int count = 1;
	int count_curr = 1;
	int nn = 1;
	substring = s[0];
	while (i < n-1)
	{
		nn = substring.length();
		for( int j = 0; j < nn; j++)
			if(s[curr+1] == substring[j]) {flag = 1; break;}
		if(flag == 0) 
		{
			substring.append(1, s[curr+1]);
			count_curr++;
			curr++;
			if(curr == n-1)
			{
				if (count_curr > count) count = count_curr; 
				return count;
			}
		}
		else
		{
			flag = 0;
			if(count_curr > count) count = count_curr;
			i++;
			substring = s[i];
			count_curr = 1;
			curr = i;
		}
	}
	return count;
}

int main()
{
	string s = "bbbbb";
	int num = lengthOfLongestSubstring(s);
	cout << num << endl;
	return 0;
}