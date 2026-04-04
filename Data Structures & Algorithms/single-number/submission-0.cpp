class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // XOR: a ^ a = 0 / a^0 = a
        int res=0;
        for (int n: nums) {
            res = res ^ n;
        }
        return res;
        //323: 011 010 011
        //res: 000->011->001->010 = 2

    }
};
