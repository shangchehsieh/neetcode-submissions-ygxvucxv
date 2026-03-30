class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);
        //the blue table {{100}, {2}, {1}, ...}
        
        //hashmap
        for (int c : nums) {
            count[c]++;
        }
        // hashmap append into the blue table
        for (const auto& entry : count) {
            freq[entry.second].push_back(entry.first);
            //entry.first是那個數字; entry.second是頻率
            //i.e. freq[頻率] = 那個數字
        }
        
        vector<int> res;
        for (int i = nums.size(); i > 0; i--) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};