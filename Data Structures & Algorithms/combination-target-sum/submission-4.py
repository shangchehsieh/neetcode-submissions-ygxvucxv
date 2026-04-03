class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res, subset = [], []
        sum = 0

        def dfs(index, sum):
            if sum > target: return
            if sum == target:
                res.append(subset.copy())
                return
            
            for i in range(index, len(nums)):
                subset.append(nums[i])
                dfs(i, sum + nums[i])
                subset.pop()

        dfs(0, sum)
        return res