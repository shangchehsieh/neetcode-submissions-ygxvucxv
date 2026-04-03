class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res, subset = [], []
        candidates.sort()
        sum = 0

        def dfs(index, sum):
            if sum>target: return
            if sum == target:
                res.append(subset.copy())
                return
            
            for i in range(index, len(candidates)):
                if (i>index and candidates[i] == candidates[i-1]): continue
                subset.append(candidates[i])
                dfs(i+1, sum+candidates[i])
                subset.pop()

        dfs(0, 0)
        return res