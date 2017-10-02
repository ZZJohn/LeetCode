public double findMedianSortedArrays(int[] nums1, int[] nums2)
{
    int l1 = nums1.length;
    int l2 = nums2.length;
    int[] sh = (l1>l2)? nums2 : nums1;
    int[] lo = (l1>l2)? nums1 : nums2;
    l1 = sh.length;
    l2 = lo.length;
    int imin = 0, imax = l1, mid = (l1+l2+1)/2;
    while(imin <= imax)
    {
        int i = (imin+imax)/2;
        int j = mid-i;
        if(j<l2 && i>0 && sh[i-1] > lo[j])
            imax = i-1;
        else if(j>0 && i<l1 && lo[j-1] > sh[i])
            imin = i+1;
        else
        {
            int num1;
            int num2;
            if(i==0)
                num1 = lo[j-1];
            else if(j==0)
                num1 = sh[i-1];
            else
                num1 = Math.max(sh[i-1], lo[j-1]);
            if((l1+l2)%2 == 1)
                return num1;
            if(i==l1)
                num2 = lo[j];
            else if(j==l2)
                num2 = sh[i];
            else
                num2 = Math.min(sh[i], lo[j]);
            return (num1+num2)/2.0;
        }
    }
    return 0;
}