class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res, subset = [], []

        def dfs(i):
            if len(subset) == len(nums):
                res.append(subset.copy())
                return
            for i in range(0, len(nums)):
                if nums[i] in subset: continue
                subset.append(nums[i])
                dfs(i+1)
                subset.pop()
        
        dfs(0)
        return res;