class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> data_set;

        for(auto num : nums){
            if(data_set.find(num) != data_set.end())
                return true;
            data_set.insert(num);   
        }

        return false;

    }
};