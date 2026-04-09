class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorr = nums.size() ;
        for (int i=0; i<nums.size(); i++) {
            xorr ^= i^nums[i];
        }
        return xorr;
    }
};
