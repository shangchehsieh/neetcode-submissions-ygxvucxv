class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;
    int sum;

    vector<vector<int>> permute(vector<int>& nums) {
        sum = accumulate(nums.begin(), nums.end(), 0);
        dfs(sum, nums);
        return res;
    }

    void dfs(int sum, vector<int>& nums) {
        if (subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            if (find(subset.begin(), subset.end(), nums[i]) != subset.end()) {
                continue; 
            }
            subset.push_back(nums[i]);
            dfs(sum-nums[i], nums);
            subset.pop_back();
        }
    }
};
