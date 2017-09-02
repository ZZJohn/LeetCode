public boolean isAnagram(String s, String t)
{
	int[] count = new int[26];
	int m = s.length();
	int n = t.length();
	if(m!=n)
		return false;
	if(m==0)
		return true;
	for(int i=0; i<=m-1; i++)
	{
		count[s.charAt(i)-'a']++;
		count[t.charAt(i)-'a']--;
	}
	for(int i=0; i<=25; i++)
		if(count[i] != 0)
			return false;
	return true;
}