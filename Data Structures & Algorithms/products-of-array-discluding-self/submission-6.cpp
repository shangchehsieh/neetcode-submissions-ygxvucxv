class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1); //step1

        int prefix = 1;
        for (int i = 0; i<n; i++) {//step2
            res[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        for (int j = n-1; j>-1; j--) {//step3
            res[j] *= postfix;
            postfix *= nums[j];
        }
        return res;
    }
};
