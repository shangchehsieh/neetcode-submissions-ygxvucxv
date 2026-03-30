class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = []
        for i in range(len(nums)): #0~3
            tmp = 1
            for j in range(len(nums)):
                if j == i: continue #j=0 i=1
                tmp *= nums[j]
            res.append(tmp)
        return res
            
            