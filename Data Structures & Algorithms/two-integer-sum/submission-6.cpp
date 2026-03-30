class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap; //index, val
        for (int i=0; i<nums.size(); i++) {
            int diff = target - nums[i];
            if (hashmap.find(diff) != hashmap.end()) {
                return {hashmap[diff], i};
            }
            hashmap.insert({nums[i], i});
        }
        return {};
    }
};
