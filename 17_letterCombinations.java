public List<String> letterCombinations(String digits) {
	List<String> res = new ArrayList<String>();
	int n = digits.length();
	if(n==0) return res;
	String[] map = new String[]{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	res.add("");
	for(int i=0; i<=digits.length()-1; i++)
	{
		List<String> tmp = new ArrayList<String>();
		int s = Character.getNumericValue(digits.charAt(i));
		if(s<=1) continue;
		for(int j=0; j<=res.size()-1; j++)
			for(int k=0; k<=map[s].length()-1; k++)
				tmp.add(res.get(j)+map[s].charAt(k));
		res = tmp;
	}
	return res;
}