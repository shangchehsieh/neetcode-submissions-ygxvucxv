class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> set_num(nums.begin(), nums.end());
        if (nums.size() != set_num.size()) {
            return true;
        }
        return false;
    }
};