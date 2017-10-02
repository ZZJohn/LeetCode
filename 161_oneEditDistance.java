public boolean isOneEditDistance(String s, String t)
{
	if(Math.abs(s.length()-t.length())>=2)
		return false;
	if(s.length() == t.length())
		return isOneMod(s, t);
	else if(s.length()-t.length() == 1)
		return isOneDel(s, t);
	else
		return isOneDel(t, s);
}

private boolean isOneMod(String s, String t)
{
	int diff = 0;
	for(int i=0; i<=s.length()-1; i++)
		if(s.charAt(i)!=t.charAt(i))
			diff++;
	return diff == 1;
}

private boolean isOneDel(String s, String t)
{
	if(t.isEmpty()) return true;
	for(int i=0; i<=t.length()-1; i++)
	{
		if(s.charAt(i)!=t.charAt(i))
			return s.substring(i+1) == t.substring(i);
	}
	return true;
}