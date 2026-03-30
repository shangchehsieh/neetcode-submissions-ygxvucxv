class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int res = 0;

        for (int i : nums) {
            if (!hashmap[i]) { //
                hashmap[i] = hashmap[i-1] + hashmap[i+1] + 1;
                hashmap[i - hashmap[i-1]] = hashmap[i];
                hashmap[i + hashmap[i+1]] = hashmap[i];
                res = max(res, hashmap[i]);
            }
        }
        return res;
    }
};
