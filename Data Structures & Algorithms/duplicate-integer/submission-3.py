class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        nums.sort()
        dup = 0
        for i in range(len(nums)-1):
            if nums[i] == nums[i+1]:
                dup += 1
        return dup>0