class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int longest = 0;//紀錄最長的車
        for (int i : nums_set) {
            if (nums_set.find(i-1) == nums_set.end()) { // i-1不在 ->車頭
                int length = 1;
                while (nums_set.find(i+length) != nums_set.end()) {
                    //i+1, i+2在 ->length增加直到看到車尾
                    length++;
                }
                longest = max(longest, length); //更新 衛冕者vs新挑戰者 誰的車長
            }
        }
        return longest;
    }
    
};
