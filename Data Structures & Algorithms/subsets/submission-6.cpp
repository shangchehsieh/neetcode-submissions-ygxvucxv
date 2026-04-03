class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;
    vector<vector<int>> subsets(vector<int>& nums) {
        //[1] or []

        dfs(0, res, nums);
        return res;
    }

void dfs(int index, vector<vector<int>>& res, vector<int>& nums) {
    res.push_back(subset);
    for (int i=index; i<nums.size(); i++) {
        subset.push_back(nums[i]);
        dfs(i+1, res, nums);
        subset.pop_back();
        }
    }
};
