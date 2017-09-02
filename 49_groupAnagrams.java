public List<List<String>> groupAnagrams(String[] strs)
{
	if(strs == null)
		return new ArrayList<List<String>>();
	int n = strs.length;
	Map<String, List<String>> map = new HashMap<>();
	Arrays.sort(strs);
	int count = 0;
	for(int i=0; i<=n-1; i++)
	{
		char[] ca = strs[i].toCharArray();
		Arrays.sort(ca);
		String key = String.valueOf(ca);
		if(!map.containsKey(key))
			map.put(key, new ArrayList<String>());
		map.get(key).add(strs[i]);
	}
	return new ArrayList<List<String>>(map.values());
}