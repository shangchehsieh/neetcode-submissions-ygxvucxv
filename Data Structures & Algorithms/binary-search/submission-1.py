class Solution:
    def search(self, nums: List[int], target: int) -> int:

        l,r = 0, len(nums)-1 #l=0, r=5
        
        
        while l <= r:

            m = (l+r) // 2 #m=2
            if target > nums[m]: #target index 345
                l = m + 1
            elif target < nums[m]: #target index 1
                r = m - 1
            else:
                return m
        return -1