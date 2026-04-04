class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res, subset = [], []

        def dfs(i, mask):
            if len(subset) == len(nums):
                res.append(subset.copy())
                return
            for i in range(0, len(nums)):
                if not(mask & (1<<i)):
                    subset.append(nums[i])
                    dfs(i+1, mask|(1<<i))
                    subset.pop()
        
        dfs(0, 0)
        return res;