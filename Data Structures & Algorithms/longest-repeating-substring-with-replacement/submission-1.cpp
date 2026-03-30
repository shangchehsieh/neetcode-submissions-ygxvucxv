class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int res = 0;
        int maxf = 0, l = 0;
        for (int r=0; r<s.size(); r++) { // how many X? how many Y?
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);

            while ((r-l+1) - maxf > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
