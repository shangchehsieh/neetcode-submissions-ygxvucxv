class Solution:
    def hammingWeight(self, n: int) -> int:
        cnt = 0
        for i in range(32):
            if (n>>i)&1: cnt += 1
        return cnt