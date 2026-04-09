class Solution:
    def reverseBits(self, n: int) -> int:
        for i in range(16):
            mask = 0
            if (n>>i)&1 != (n>>(31-i))&1:
                mask = (1<<i) | (1<<(31-i))
                n ^= mask
        return n