class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        //build hashmap [key, value]
        for (int c : nums) {
            hashmap[c]++;
        }
        //store in a vector vec[key, value] to sort the freq
        vector<pair<int,int>> vec(hashmap.begin(), hashmap.end());
        partial_sort(vec.begin(), vec.begin()+k, vec.end(), [](auto const&a, auto const&b) {
            return a.second > b.second;
        });
        
        //build the result array
        vector<int> result;
        for (int i=0; i<k; i++) {
            result.push_back(vec[i].first);
        }
        return result;
    }
};
