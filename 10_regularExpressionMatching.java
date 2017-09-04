public static boolean isMatch(String s, String p)
{
	if(p.isEmpty()) return s.isEmpty();
	if(p.length() == 1)
		return s.length()==1 && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.');
	if(p.charAt(1) == '*')
		return isMatch(s, p.substring(2)) || 
				(!s.isEmpty() && ((s.charAt(0) == p.charAt(0)) || p.charAt(0) == '.') 
				&& isMatch(s.substring(1), p)); 
	else
		return (!s.isEmpty() && ((s.charAt(0) == p.charAt(0)) || p.charAt(0) == '.')) && isMatch(s.substring(1), p.substring(1)); 
}