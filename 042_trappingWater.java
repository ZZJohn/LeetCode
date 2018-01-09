public int trap(int[] height) 
{
	 int left = 0;
	 int right = height.length-1;
	 int maxleft = 0;
	 int maxright = 0;
	 int res = 0;
	 while(left<=right)
	 {
	 	if(height[left]<=maxright)
	 	{
	 		if(height[left]>=maxleft)
	 			maxleft = height[left];
	 		res += maxleft-height[left];
	 		left++;
	 	}
	 	else
	 	{
	 		if(height[right]>=maxright)
	 			maxright = height[right];
	 		res += maxright-height[right];
	 		right--;
	 	}
	 }
	 return res;       
}