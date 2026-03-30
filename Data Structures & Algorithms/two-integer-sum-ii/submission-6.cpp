class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //return [index1, index2]
        int l = 0, r = numbers.size()-1;
        while (numbers[l] + numbers[r] != target) {
            if (numbers[l] + numbers[r] > target) r--;//too large
            if (numbers[l] + numbers[r] < target) l++; //too small
        }
        return {l+1, r+1}; //Return the indices (1-indexed) of two numbers
    }
};