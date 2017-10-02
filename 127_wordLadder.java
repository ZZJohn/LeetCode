public int ladderLength(String beginWord, String endWord, List<String> wordList)
{
    if(!wordList.contains(endWord))
        return 0;
    wordList.remove(endWord);
    Queue<String> queue1 = new LinkedList<>();
    Queue<String> queue2 = new LinkedList<>();
    queue1.offer(beginWord);
    queue2.offer(endWord);
    if(wordList.contains(beginWord))
        wordList.remove(beginWord);
    Set<String> set = new HashSet<>();
    for(String s: wordList)
        set.add(s);
    int res = 1;
    while(!queue1.isEmpty() && !queue2.isEmpty())
    {
        Queue<String> qshort = (queue1.size()>queue2.size())?queue2:queue1;
        Queue<String> qlong = (queue1.size()>queue2.size())?queue1:queue2;
        int qshortsize = qshort.size();
        res++;
        for(int k=0; k<=qshortsize-1; k++)
        {
            char[] curr = qshort.poll().toCharArray();
            for(int i=0; i<=curr.length-1; i++)
            {
                char tmp = curr[i];
                for(char j='a'; j<='z'; j++)
                {
                    curr[i] = j;
                    String s = String.valueOf(curr);
                    if(qlong.contains(s))
                        return res;
                    if(set.contains(s))
                    {
                        qshort.offer(s);
                        set.remove(s);
                    }
                }
                curr[i] = tmp;
            }
        }
    }
    return 0;
}