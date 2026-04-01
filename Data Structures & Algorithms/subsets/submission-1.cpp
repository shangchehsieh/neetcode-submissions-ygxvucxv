class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums, subset, res);
        return res;
    }
    void dfs(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(subset); // no need to copy cuz it has automatedly copied when pushing back            subset.push_back(nums[i]);
            return;
        }
            subset.push_back(nums[i]);
            dfs(i+1, nums, subset, res);
            subset.pop_back();
            dfs(i+1, nums, subset, res);
        }
};
