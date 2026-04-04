class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return res;
    }

    void dfs(vector<int>& nums, int mask) {
        //for nums = [1,2,3] , init mask: 000 (123都還沒被用過)
        if (subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }
        for (int i=0; i< nums.size(); i++) {
            if(!(mask & (1<<i))) { //i-th mask == 0 (nums[i]還沒用過)
                subset.push_back(nums[i]);
                dfs(nums, mask| (1<<i));
                subset.pop_back();
            }
        }
    }
};
