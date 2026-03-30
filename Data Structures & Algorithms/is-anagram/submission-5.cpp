class Solution {
public:
    bool isAnagram(string s, string t) {
        //case 1: length不同
        if (s.size() != t.size()) return false;
        //case 2: length同，比較字母出現頻率(Hashmap)
        unordered_map<char,int> count_s;
        unordered_map<char,int> count_t;
        for (int i=0 ; i<s.size(); i++) {
            count_s[s[i]]++;
            count_t[t[i]]++;
        }
        return count_s == count_t;
    }
};
