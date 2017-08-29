#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find_entry(vector<vector<int>> &result, vector<int> nums, int begin, int end, int target) {
	int m = begin, n = end;
	while (m < n) {
		if (nums[m] + nums[n] + target == 0){
			vector<int> entry;
			entry.push_back(nums[m]);
			entry.push_back(target);
			entry.push_back(nums[n]);
			sort(entry.begin(), entry.begin()+3);
			result.push_back(entry);
			while (m < n && nums[m] == nums[m+1]) m++;
			while (m < n && nums[n] == nums[n-1]) n--;
			m++;
			n--;
		}
		else if (nums[m] + nums[n] + target < 0) {
			m++;
		}
		else {
			n--;
		}
	}
}

vector<vector<int>> threeSum(vector<int>& nums) {
        int len;
		vector<vector<int>> result;
		len = nums.size();
		if (nums.size() < 3) return result;
		sort(nums.begin(), nums.begin()+6);
		for (int i=0; i < len-2; i++) {
			if (i > 0 && nums[i] == nums[i-1]) continue;
			find_entry(result, nums, i+1, len-1, nums[i]);
		}
		return result;
}

int main(){
	int value[6] = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> result;
	vector<int> nums(value, value+6);
	result = threeSum(nums);
	int len = result.size();
	for (int i=0; i<len; i++)
		cout << result[i][0] << ", " << result[i][1] <<", " << result[i][2] << endl;
}