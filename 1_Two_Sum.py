def twoSum(self, nums, target):
	map = {}
	for index, value in enumerate(nums):
		if target - value in map:
			return map[target - value], index
		map[value] = index

s = twoSum(0,(1,2,3,4),7)
print(s)

