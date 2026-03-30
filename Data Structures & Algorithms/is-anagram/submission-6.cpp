class Solution {
public:
    bool isAnagram(string s, string t) {
        //case 1: length不同
        if (s.size() != t.size()) return false;
        //case 2: length同，比較字母出現頻率
        vector<int> count(26, 0);// create an array "count": size26, initialize to 0
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int val : count) {
            if (val != 0) return false;
        }
        return true;
    }
};
