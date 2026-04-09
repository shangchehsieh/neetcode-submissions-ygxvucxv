class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for (int i=0; i<16; i++) {
            //提取n的第i個bit: (n>>i)&1
            if (((n>>i)&1) != ((n>>(31-i))&1)) {// 
                uint32_t mask = (1U<<i) | (1U<<(31-i)); //1000....00001
                n ^= mask;
            }
        }
        return n;
    }
};