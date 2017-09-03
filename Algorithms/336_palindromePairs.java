public List<List<Integer>> palindromePairs(String[] words)
{
	List<List<Integer>> res = new ArrayList<>();
	int n = words.length;
	if(n<=1) return res;
	Map<String, Integer> map = new HashMap<>();
	for(int i=0; i<=n-1; i++)
	{
		map.put(words[i], i);
	}
	for(int i=0; i<=n-1; i++)
	{
		int l=0, r=0;
		while(l<=r)
		{
			String s = words[i].substring(l, r);
			Integer j = map.get(new StringBuilder(s).reverse().toString());
			if(j != null && i != j && isPalindrome(words[i].substring(l==0?r:0, l==0?words[i].length():l)))
			{
				List<Integer> pair = new ArrayList<>(Arrays.asList(l==0? new Integer[]{i, j}:new Integer[]{j, i}));
				res.add(pair);
			}
			if(r<words[i].length()) r++;
			else l++;
		}
	}
	return res;
}

public boolean isPalindrome(String str)
{
	int n = str.length();
	for(int i=0; i<=n/2-1; i++)
	{
		if(str.charAt(i) != str.charAt(n-1-i))
			return false;
	}
	return true;
}