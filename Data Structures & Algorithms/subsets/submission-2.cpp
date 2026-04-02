class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //[1] or []
        vector<vector<int>> res;
        vector<int> subset;
        dfs(0, res, subset, nums);
        return res;
    }


void dfs(int i, vector<vector<int>>& res, vector<int>& subset, vector<int>& nums) {
    if (i >= nums.size()) {
        res.push_back(subset);
        return;
    }
    subset.push_back(nums[i]);
    dfs(i+1, res, subset, nums);
    subset.pop_back();
    
    dfs(i+1, res, subset, nums);
    }
};
