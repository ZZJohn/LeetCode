public int firstMissingPositive(int[] nums) 
{
    int n = nums.length;
    int i = 0;
    while(i<=n-1)
    {
        if(nums[i] > 0 && nums[i]<=n && nums[nums[i]-1]!=nums[i])
        {
            int tmp = nums[nums[i]-1];
            nums[nums[i]-1] = nums[i];
            nums[i] = tmp;
        }
        else
            i++;
    }
    for(i=0; i<=n-1; i++)
        if(nums[i] != i+1)
            return i+1;
    return n+1;
}