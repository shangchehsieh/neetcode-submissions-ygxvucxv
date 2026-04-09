class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int num_sum = 0;
        for (int i=0; i<=nums.size(); i++) {
            sum += i;
            if (i == nums.size()) break;
            num_sum += nums[i];
        }
        cout << sum << endl;
        cout << num_sum << endl;
        return sum-num_sum;
    }
};
