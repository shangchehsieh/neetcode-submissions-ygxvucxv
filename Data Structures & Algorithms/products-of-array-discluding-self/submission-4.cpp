class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i<nums.size(); i++) {
            int tmp = 1;
            for (int j = 0; j<nums.size(); j++) {
                if (i == j) continue;
                tmp *= nums[j];
            }
            res.push_back(tmp);
        }
        return res;
    }
};
