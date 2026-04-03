class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;

    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return res;
    }

    void dfs(vector<int>& nums) {
        if (subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            if (find(subset.begin(), subset.end(), nums[i]) != subset.end()) {
                continue; 
            }
            subset.push_back(nums[i]);
            dfs(nums);
            subset.pop_back();
        }
    }
};
