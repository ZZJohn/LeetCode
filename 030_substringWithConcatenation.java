public List<Integer> findSubstring(String s, String[] words)
{
    Map<String, Integer> wordsCount = new HashMap<>();
    for(String word:words)
    {
        if(wordsCount.containsKey(word)==false)
            wordsCount.put(word, 0);
        wordsCount.put(word, wordsCount.get(word)+1);
    }
    List<String> wordsList = new ArrayList<>(Arrays.asList(words));
    int wl = words[0].length();
    int n = s.length();
    int wn = words.length;
    List<Integer> res = new ArrayList<>();
    for(int i=0; i<=wl-1; i++)
    {
        int left = i;
        int count = 0;
        Map<String, Integer> tmp = new HashMap<>();
        for(int j=i; j<=n-wl; j+=wl)
        {
            String t = s.substring(j, j+wl);
            if(wordsCount.containsKey(t))
            {
                tmp.put(t, tmp.getOrDefault(t, 0)+1);
                count++;
                if(tmp.get(t)==wordsCount.get(t))
                {
                    if(count==wn)
                    {
                        res.add(left);
                        count--;
                        tmp.put(s.substring(left, left+wl), tmp.get(s.substring(left, left+wl))-1);
                        left += wl;
                    }
                }
                else
                {
                    while(tmp.get(t)>=wordsCount.get(t)+1)
                    {
                        String tt = s.substring(left, left+wl);
                        tmp.put(tt, tmp.get(tt)-1);
                        count--;
                        left += wl;
                    }
                }
            }
            else
            {
                count = 0;
                left = j+wl;
                tmp.clear();
            }
        }
    }
    return res;
}