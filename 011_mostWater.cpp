int maxArea(vector<int>& height)
{
	int n = height.size();
	int l = 0, r = n-1;
	int maxArea = 0;
	while(l < r)
	{
		int area = min(height[l], height[r]) * (r-l);
		if(area > maxArea) maxArea = area;
		if(height[l] <= height[r]) l++;
		else r--;
	}
	return maxArea;
}
