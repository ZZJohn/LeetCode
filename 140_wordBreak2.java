Map<Integer, List<String>> map = new HashMap<>();
public List<String> wordBreak(String s, List<String> wordDict) 
{
    Set<String> wordSet = new HashSet<>(wordDict);
    return helper(s, wordSet, 0);
}

public List<String> helper(String s, Set<String> wordSet, int start)
{
    if(map.containsKey(start))
        return map.get(start);
    List<String> res = new ArrayList<>();
    if(start == s.length())
        res.add("");
    for(int end=start+1; end<=s.length(); end++)
    {
        if(wordSet.contains(s.substring(start, end)))
        {
            List<String> prevs = helper(s, wordSet, end);
            for(String prev: prevs)
            {
                res.add(s.substring(start, end) + ((prev.equals(""))?"":" ") + prev);
            }
        }
    }
    map.put(start, res);
    return res;
}	