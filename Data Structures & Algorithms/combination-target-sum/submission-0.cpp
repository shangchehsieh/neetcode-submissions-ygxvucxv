class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;
    int t;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        t = target;
        int sum = 0;
        dfs(0, nums, sum, subset, res, 0);
        return res;
    }

    void dfs(int i, vector<int>& nums, int sum, vector<int>& subset, vector<vector<int>>& res, int start) {
        if (sum > t) return;
        if (sum == t) {
            res.push_back(subset);
            return;
        }
        
        for(int i=start; i<nums.size(); i++){
            //choose nums[i]
            subset.push_back(nums[i]);
            dfs(i, nums, sum + nums[i], subset, res, i);
            subset.pop_back();
        }
    }
};
