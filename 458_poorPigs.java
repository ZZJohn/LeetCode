public int poorPigs(int buckets, int minutesToDie, int minutesToTest) 
{
    if(buckets<=1)
        return 0;
    int k = minutesToTest/minutesToDie+1;
    int i = 1;
    while(Math.pow(k, i)<buckets)
        i++;
    return i;  
}