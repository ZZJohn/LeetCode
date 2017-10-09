public int combinationSum4(int[] nums, int target) 
{
    int[] res = new int[target+1];
    for(int i=1; i<=target; i++)
    {
        for(int num: nums)
        {
            if(num>i)
                continue;
            else if(num==i)
                res[i] += 1;
            else
                res[i] += res[i-num];
        }
    } 
    return res[target];
}