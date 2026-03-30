class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        vector<int> pref(n, 0);
        vector<int> suff(n, 0);
        pref[0] = 1;
        suff[n-1] = 1;
        for (int i = 1; i<n; i++) {
            pref[i] = pref[i-1] * nums[i-1];
        }
        for (int j = n-2; j>-1; j--) {
            suff[j] = suff[j+1] * nums[j+1];
        }
        for (int k = 0; k<n; k++) {
            res[k] = pref[k] * suff[k];
        }
        return res;
    }
};
