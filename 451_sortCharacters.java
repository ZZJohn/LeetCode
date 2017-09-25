public String frequencySort(String s) 
{
    int n = s.length();
    if(n==0 || n==1)
        return s;
    Map<Character, Integer> map = new HashMap<>();
    for(int i=0; i<=n-1; i++)
    {
        char c = s.charAt(i);
        if(map.containsKey(c))
            map.put(c, map.get(c)+1);
        else
            map.put(c, 1);
    }
    List<Character>[] bucket = new List[n+1];
    for(char key: map.keySet())
    {
        int freq = map.get(key);
        if(bucket[freq] == null)
            bucket[freq] = new ArrayList<Character>();
        bucket[freq].add(key);
    }
    StringBuilder sb = new StringBuilder();
    for(int i=n; i>=0; i--)
    {
        if(bucket[i] != null)
        {
            for(char c: bucket[i])
                for(int j=0; j<=i-1; j++)
                    sb.append(c);
        }
    }
    return sb.toString();
}