public String minWindow(String s, String t)
{
	Map<Character, Integer> map = new HashMap<>();
	int nt = t.length();
	for(int i=0; i<=nt-1; i++)
	{
		int value = 0;
		if(map.containsKey(t.charAt(i)))
			value = map.get(t.charAt(i));
		map.put(t.charAt(i), value+1);
	}
	int begin=0, end=0, head=0, counter=0, res=Integer.MAX_VALUE;
	while(end <= s.length()-1)
	{
		if(map.containsKey(s.charAt(end)))
		{
			int value = map.get(s.charAt(end));
			if(value > 0)
				counter++;
			map.put(s.charAt(end), value-1);
		}
		end++;
		while(counter == nt)
		{
			if(end-begin < res)
			{
				res = Math.min(res, end-begin);
				head = begin;
			}
			if(map.containsKey(s.charAt(begin)))
			{
				int value = map.get(s.charAt(begin));
				if(value == 0)
					counter--;
				map.put(s.charAt(begin), value+1);
			}
			begin++;
		}
	}
	return res==Integer.MAX_VALUE?"":s.substring(head, head+res);
}